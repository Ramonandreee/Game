# 07 — NPC & Agent AI Architecture

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 07 de 12 · Confidencial
> *Inclui: Agent AI, Networking Systems, Reputation Systems*

---

## 1. A Tese de IA

> **Não queremos NPCs. Queremos agentes. Cada pessoa importante em Meridian é uma mente persistente: com personalidade, memória de anos, objetivos próprios e a capacidade de agir no mundo independentemente do jogador.**

Este é o maior **moat tecnológico** de MOGUL (ver [02-Market](02-MARKET-ANALYSIS.md)). A diferença entre um "NPC" tradicional e um "agente" MOGUL:

| NPC tradicional | Agente MOGUL |
|-----------------|--------------|
| Diálogo em árvore fixa | Conversa dinâmica, contextual |
| Sem memória entre encontros | Lembra de você por anos de jogo |
| Comportamento roteirizado | Persegue objetivos próprios |
| Estático no mundo | Vive uma rotina, age sozinho |
| Reage só ao jogador | Age com ou sem o jogador |
| Personalidade plana | Big Five completo, motivações, medos |

## 2. O Desafio Central: Escala vs. Profundidade

Não é viável (custo/latência/performance) rodar uma "mente de IA pesada" para cada um dos milhares de habitantes de Meridian. A solução é uma **arquitetura de IA em camadas de profundidade (LOD de cognição)** — gastamos cognição onde importa.

```
┌──────────────────────────────────────────────────────────────┐
│ TIER 0 — AMBIENTAIS (dezenas de milhares)                     │
│  Multidões, tráfego. Mass Entity puro. Sem mente.             │
│  Custo: ~zero. Servem à densidade visual ([04-World]).        │
├──────────────────────────────────────────────────────────────┤
│ TIER 1 — FUNCIONAIS (milhares)                                │
│  Lojistas, atendentes, funcionários genéricos. Estado +       │
│  comportamento por regras/utility AI. Promovíveis a Tier 2.   │
├──────────────────────────────────────────────────────────────┤
│ TIER 2 — SOCIAIS PERSISTENTES (centenas–milhares)             │
│  Contatos, funcionários-chave, rivais, investidores.          │
│  Personalidade Big Five + memória + objetivos + rotina.       │
│  Cognição "barata" (utility + behavior trees + GOAP) +        │
│  memória em knowledge graph. SEM LLM por padrão.              │
├──────────────────────────────────────────────────────────────┤
│ TIER 3 — PROTAGONISTAS (dezenas ativos por vez)               │
│  Os NPCs com quem o jogador interage de perto AGORA.          │
│  Tudo do Tier 2 + diálogo generativo (LLM/SLM) contextual.    │
│  "Hidratados" sob demanda; voltam ao Tier 2 ao sair de cena.  │
└──────────────────────────────────────────────────────────────┘
```

> **Princípio:** um NPC pode ser **promovido/rebaixado** de tier conforme sua relevância para o jogador. Aquele atendente de café (Tier 1) que você decidiu cortejar como contato vira Tier 2; quando vocês conversam, ele "hidrata" para Tier 3. Isso concentra o orçamento de IA nos ~dezenas de agentes que importam *naquele momento*.

## 3. Anatomia de um Agente (Tier 2/3)

Cada agente profundo é composto por quatro subsistemas: **Perfil, Personalidade, Memória, Comportamento.**

### 3.1 Perfil (a ficha)
Dados factuais que definem quem o agente é no mundo:
- **Identidade:** nome, idade, gênero, aparência (MetaHuman).
- **Background:** formação, história, origem social.
- **Profissão & papel:** o que faz, onde trabalha, cargo.
- **Patrimônio & status:** quão rico/influente.
- **Rede:** quem conhece, afiliações.

### 3.2 Personalidade (Big Five / OCEAN)
Cada agente tem o modelo **Big Five completo**, mais camadas:
- **Openness** — abertura a ideias novas, risco, inovação.
- **Conscientiousness** — disciplina, confiabilidade, ética de trabalho.
- **Extraversion** — sociabilidade, assertividade, energia social.
- **Agreeableness** — cooperação, empatia, vs. competitividade fria.
- **Neuroticism** — estabilidade emocional, reação a estresse.

Camadas derivadas: **motivações** (o que persegue: dinheiro, poder, status, segurança, propósito), **medos** (o que evita: ruína, humilhação, perda de controle), **objetivos** (metas de curto/longo prazo) e **valores** (ética, lealdade, ambição). A personalidade **modula tudo**: como negociam, se traem, se são leais, como reagem a você.

### 3.3 Memória (o knowledge graph)
> **A inovação central.** Agentes lembram — por **anos de tempo de jogo**.

A memória é um **grafo de conhecimento (knowledge graph)** por agente, integrado a um grafo social global:
- **Nós:** pessoas, empresas, eventos, lugares, objetos, fatos.
- **Arestas:** relações (conhece, trabalha-para, confia, deve-favor-a, odeia, fez-negócio-com).
- **Memórias episódicas:** eventos específicos com o jogador — conversas, negociações, favores, conflitos, traições, parcerias — com timestamp, contexto e **carga emocional**.
- **Memória semântica:** fatos generalizados ("o jogador é um negociador durão", "essa pessoa quebra promessas").

**Gestão de memória (para escalar):**
- **Saliência & decaimento:** memórias têm peso por importância e emoção; memórias triviais decaem/comprimem; memórias marcantes (uma traição) persistem por anos.
- **Sumarização:** memórias antigas são comprimidas em "impressões" semânticas (preserva o *sentimento* sem guardar cada detalhe — barato em armazenamento).
- **Recuperação (retrieval):** ao interagir, o agente recupera as memórias *relevantes* ao contexto para informar comportamento e diálogo (RAG sobre o grafo do agente).

(Persistência técnica do grafo em [10-Tech](10-TECHNICAL-ARCHITECTURE.md).)

### 3.4 Comportamento (o que o agente faz)
- **Rotina diária:** acordar, trabalhar, almoçar, viajar, investir, fazer networking, dormir — uma agenda crível que coloca o agente *no mundo* em lugares plausíveis (você pode "esbarrar" nele).
- **Tomada de decisão:** **Utility AI + GOAP (Goal-Oriented Action Planning)** — o agente pondera ações pela utilidade dada sua personalidade, objetivos, memória e estado do mundo. (Empresas-IA usam o mesmo motor em escala estratégica — ver [06-Business](06-BUSINESS-SYSTEMS.md) §8.)
- **Reatividade:** responde a eventos (recebeu uma proposta, ouviu uma fofoca, viu um rival prosperar) atualizando objetivos e memória.

## 4. Diálogo Generativo (Tier 3) — A Camada LLM

Quando o jogador conversa de perto com um agente, ele "hidrata" para diálogo generativo.

### 4.1 Arquitetura híbrida de diálogo (a decisão crítica de custo/risco)
> Risco-chave do projeto: custo, latência e confiabilidade de LLMs ([12-Risk](12-BUSINESS-PLAN.md)). Mitigação = **arquitetura híbrida em cascata**.

```
Input do jogador
   │
   ▼
[1] INTENT PARSER (local, barato) — classifica a intenção
   │
   ├─► Intenção "mecânica" (negociar, ofertar, perguntar fato)
   │      └─► resolvida por SISTEMA + diálogo TEMPLATED/curado (determinístico, 0 custo, 0 risco)
   │
   └─► Intenção "aberta" (conversa livre, social, exploratória)
          └─► [2] GERAÇÃO:
                ├─ Preferência 1: SLM LOCAL (modelo pequeno on-device) — barato, privado, rápido
                ├─ Preferência 2: LLM CLOUD (qualidade alta) para momentos importantes
                └─ Fallback: respostas curadas por personalidade (se offline / orçamento estourado)
```

### 4.2 Grounding & guard-rails (impedir alucinação e quebra de imersão)
- **O LLM não decide fatos nem regras do jogo.** Ele apenas *verbaliza*. A "verdade" vem do **knowledge graph + estado de jogo**, injetada no prompt como contexto (grounding via RAG).
- **Persona-locked:** o agente fala *em personagem* — prompt construído a partir do Perfil + Big Five + memórias relevantes + objetivos atuais + mood.
- **Ações via function-calling estruturado:** se o NPC "decide" algo (aceitar uma oferta, marcar reunião), isso passa por **tool/function calls validadas pelo sistema** — o LLM nunca altera o estado diretamente. (Padrão de tool-use com validação; ver [10-Tech](10-TECHNICAL-ARCHITECTURE.md).)
- **Safety & consistência:** filtros de conteúdo, limites de tópico, e verificação de consistência (não contradizer fatos do grafo). Tudo em conformidade com classificação etária (ver [12](12-BUSINESS-PLAN.md)).
- **Determinismo opcional:** modo "sem IA generativa" (100% diálogo curado) disponível para jogadores/plataformas que preferirem — o jogo é **totalmente jogável sem a camada LLM**, que é um *enhancement*, não uma dependência crítica.

### 4.3 Por que isso é defensável
A qualidade não vem do LLM (qualquer um tem um) — vem da **integração**: o knowledge graph + memória persistente + Big Five + economia de agentes que *alimenta* o LLM com contexto verdadeiro e consequente. Esse é o moat (ver [02-Market](02-MARKET-ANALYSIS.md) §5).

## 5. Networking — Mecânica Principal

> **Networking não é um menu. É a principal forma de destravar o jogo.** Relações abrem portas que dinheiro não abre.

### 5.1 O loop de networking
```
ENCONTRAR (esbarrar / buscar) → ABORDAR → CONVERSAR (descobrir) →
CONECTAR (trocar contato) → CULTIVAR (favores, follow-up) →
ATIVAR (pedir/oferecer: deal, intro, investimento, talento, info)
```

### 5.2 Encontros orgânicos (o exemplo da cafeteria)
O exemplo canônico do design: você está num café e percebe alguém numa mesa ao lado. Você pode:
1. **Observar** — ler sinais (roupa, postura, conversa) que sugerem quem é/seu status.
2. **Abordar** — iniciar conversa (sucesso depende de carisma, contexto, timing).
3. **Descobrir** — através da conversa, revelar gradualmente: quem é, o que faz, patrimônio aproximado, objetivos, dores.
4. **Avaliar** — esta pessoa é útil? (um investidor? um talento? um futuro cliente? um rival disfarçado?)
5. **Conectar** — trocar contatos, marcar um próximo encontro.

> Esses encontros são **semi-emergentes**: a rotina dos agentes ([§3.4]) os coloca em lugares plausíveis; o jogo aumenta sutilmente a chance de encontros *relevantes* (um VC aparece no café perto do distrito tech) sem que pareça roteirizado.

### 5.3 Descoberta progressiva de informação
Você não sabe tudo sobre um contato de cara. Informação é **revelada por relação**: quanto mais próximo/confiável, mais você descobre (patrimônio real, objetivos ocultos, conexões, segredos). Isso torna o networking um **jogo de informação** — saber quem alguém *realmente* é vale ouro (e habilita insider deals, due diligence informal, etc. — ver [05-Economy](05-ECONOMY-DESIGN.md), [06-Business](06-BUSINESS-SYSTEMS.md)).

### 5.4 O grafo social (a teia de relações)
- Todas as relações vivem num **grafo social global** conectando jogador, agentes e empresas.
- **Conexões indiretas importam:** "amigo de amigo" — você pode pedir a um contato que te **apresente** a alguém (introductions são uma mecânica-chave; quem você conhece define quem você *pode* conhecer).
- **Capital social** é um recurso: favores devidos/a receber, força e qualidade da rede. A rede tem valor mensurável e estratégico.
- **Círculos & gatekeeping:** acesso a certos círculos (ex.: o Apex Club em Goldhaven — [04-World](04-WORLD-DESIGN.md)) é gated por reputação e por *quem te apresenta*.

### 5.5 Tipos de relação
Conhecidos → Contatos → Aliados → Sócios/Parceiros → Mentores/Protegidos → Rivais → Inimigos. Cada tipo tem dinâmica e benefícios/riscos próprios, e pode **evoluir ou degradar** com base em ações e memória ([§3.3]).

## 6. Sistema de Reputação — Multidimensional

> **Não há uma "barra de reputação". Há muitas — e cada audiência te julga por critérios diferentes.**

### 6.1 As sete reputações
| Reputação | Como se ganha/perde | O que destrava/trava |
|-----------|---------------------|----------------------|
| **Funcionários** | Liderança justa, cultura, pagar bem | Atração/retenção de talento, produtividade, lealdade |
| **Clientes** | Qualidade, confiança, atendimento | Demanda, lealdade de marca, boca-a-boca |
| **Investidores** | Track record, retornos, transparência | Acesso a capital, termos melhores, valuations |
| **Governo** | Compliance, lobby, impostos, empregos | Licenças, contratos públicos, regulação favorável, risco de fiscalização |
| **Mercado (pares/setor)** | Sucesso, respeito de rivais, conduta | Parcerias, deals, alianças, respeito em negociações |
| **Mídia** | Relacionamento com imprensa, histórias | Narrativa pública (herói vs. vilão), cobertura, controle de crise |
| **Público (geral)** | Imagem, filantropia, escândalos | Fama, fantasia "figura pública", influência de massa, valor de marca pessoal |

### 6.2 Mecânica de reputação
- **Independentes mas interligadas:** alta reputação com investidores não te dá reputação pública. Mas trade-offs existem: demitir em massa pode agradar investidores e *destruir* reputação com funcionários e público.
- **Contextual e lembrada:** reputações são memória agregada do grafo social ([§3.3]) + percepção da mídia-IA. Um escândalo **propaga** entre audiências em velocidades diferentes (a mídia espalha; funcionários reagem; investidores reavaliam).
- **Manifestação diegética:** reputação não é um número escondido — é *sentida*. Você é reconhecido (ou barrado) ao entrar num lugar; tratado com deferência ou desdém; sua reputação precede você em negociações.
- **Recuperável (com custo):** escândalos podem ser superados com tempo, RP, filantropia, ou novos sucessos — mas o grafo *lembra*, e certas traições deixam cicatrizes permanentes em relações específicas.

### 6.3 Reputação pessoal vs. de marca
- **Reputação pessoal** (você, o magnata) ≠ **reputação de marca** (cada empresa — ver [06-Business](06-BUSINESS-SYSTEMS.md) §9). Você pode ter má fama pessoal e marcas adoradas, ou vice-versa. Gerenciar a relação entre as duas é gameplay de endgame (ex.: distanciar sua imagem de uma marca em crise).

## 7. Consequência & Emergência (o pagamento de tudo isso)

A combinação de **agentes com memória + grafo social + reputação multidimensional + economia autônoma** produz a promessa central do Pilar II ([01-Vision](01-PRODUCT-VISION.md)): **histórias emergentes consequentes**. Exemplos do tipo de narrativa que o sistema gera *sem roteiro*:

- Um funcionário que você humilhou anos atrás sai, funda um rival, e lidera uma aquisição hostil contra você — por vingança lembrada.
- Um contato casual de um café na Fase 1 vira, dez anos depois, o investidor que salva seu império numa crise — porque você cultivou a relação.
- Uma traição num deal vaza pela mídia, destrói sua reputação no mercado, e fecha portas que você nem sabia que tinha.

> Estas histórias são o produto. Elas são o que os jogadores vão clipar e compartilhar (ver persona "Criador de Conteúdo", [02-Market](02-MARKET-ANALYSIS.md)) — e são impossíveis de replicar sem a stack completa.

## 8. Resumo da Stack de IA & Conexões Técnicas
| Componente | Tecnologia | Doc |
|------------|-----------|-----|
| Multidões/tráfego | Mass Entity (ECS) | [10-Tech](10-TECHNICAL-ARCHITECTURE.md) |
| Decisão de agentes | Utility AI + GOAP + Behavior Trees | aqui §3.4 |
| Memória | Knowledge graph por agente + grafo social global | [10-Tech](10-TECHNICAL-ARCHITECTURE.md) |
| Diálogo | Híbrido: templated + SLM local + LLM cloud + RAG grounding | aqui §4 |
| Empresas-IA | Mesmo motor de decisão, escala estratégica | [06-Business](06-BUSINESS-SYSTEMS.md) §8 |
| Aparência | MetaHuman | [10-Tech](10-TECHNICAL-ARCHITECTURE.md) |

---

> **Anterior:** [← 06 — Business Systems](06-BUSINESS-SYSTEMS.md) · **Próximo:** [08 — Real Estate & Vehicle Systems →](08-ASSETS-SYSTEMS.md)

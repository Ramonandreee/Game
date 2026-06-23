# 09 — UX/UI Design

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 09 de 12 · Confidencial
> *Inclui: User Interface, UX Flows, Accessibility*

---

## 1. O Desafio de UX Central

> **Como entregar a profundidade de uma simulação econômica da Paradox sem trair o Pilar I ("Viva o Império" — sem planilhas frias, sem menus como interface primária)?**

Esta é a **tensão de design mais difícil de MOGUL**. A resposta é uma filosofia de **interface diegética em camadas**: a informação vive *no mundo* sempre que possível; e quando precisa de uma "tela", essa tela é parte da ficção e revela profundidade *progressivamente*, sob demanda.

## 2. Princípios de UI

1. **Diegese primeiro.** A informação deve existir no mundo antes de existir num HUD. Você não tem uma "barra de reputação" — você é tratado de forma diferente. Você não tem um menu de "contratar" — você entrevista alguém.
2. **Progressão de profundidade (progressive disclosure).** A camada de superfície é simples e narrativa (um CFO-IA diz "o caixa está apertado"). A profundidade (a DRE completa) está a um clique, para quem quer. Ninguém é forçado à planilha; ninguém é privado dela.
3. **Tradução, não exposição.** Sistemas complexos são *traduzidos* por personagens (consultores-IA) em linguagem humana e acionável, em vez de despejar números crus.
4. **Legibilidade de consequência.** O jogador deve **sempre** poder responder "por que isso aconteceu?". Causalidade é rastreável (ver §6).
5. **Status sentido, não exibido.** Status é comunicado pela reação do mundo, não por um número no HUD (ver [08-Assets](08-ASSETS-SYSTEMS.md) §5).
6. **Beleza é função.** Numa fantasia de luxo e poder, a própria UI deve ser *aspiracional* — elegante, premium, satisfatória de usar.

## 3. A Arquitetura de Interface em Três Camadas

```
┌─────────────────────────────────────────────────────────────┐
│ CAMADA 1 — O MUNDO (diegese pura)                            │
│  Caminhar, conversar, observar, agir fisicamente.            │
│  A interface é a realidade. ~80% do tempo aqui.              │
├─────────────────────────────────────────────────────────────┤
│ CAMADA 2 — DISPOSITIVOS DIEGÉTICOS                           │
│  O "smartphone" do avatar; telas in-game; documentos;       │
│  o terminal do PC; o tablet de apresentação.                │
│  Interface estilizada COMO objeto do mundo.                  │
├─────────────────────────────────────────────────────────────┤
│ CAMADA 3 — VISÕES ANALÍTICAS (deep dive opcional)           │
│  Dashboards completos, demonstrativos, org charts, mercado. │
│  Para quem quer otimizar. Acessível, nunca obrigatória.     │
└─────────────────────────────────────────────────────────────┘
```

### 3.1 Camada 2 — O "MeridianOS" (o hub diegético)
O dispositivo central do jogador é um **smartphone/tablet in-fiction ("MeridianOS")** — a metáfora perfeita: todo empresário moderno comanda do telefone, então um hub baseado em apps é *diegético por natureza*.

Apps do MeridianOS (cada um é um sistema):
| App | Função | Sistema |
|-----|--------|---------|
| **Mensagens** | Comunicação com contatos/agentes; deals por texto | [07-AI](07-NPC-AI-ARCHITECTURE.md) |
| **Contatos / Rede** | Seu grafo social, relações, follow-ups | [07-Networking](07-NPC-AI-ARCHITECTURE.md) §5 |
| **Empresas** | Painel resumido das suas empresas (resumo do CFO-IA) | [06-Business](06-BUSINESS-SYSTEMS.md) |
| **Banco / Finanças** | Patrimônio, contas, crédito, transferências | [05-Economy](05-ECONOMY-DESIGN.md) §7 |
| **Mercado (MerEx)** | Ações, investimentos, trading | [05-Economy](05-ECONOMY-DESIGN.md) §8 |
| **Notícias** | Mídia-IA: o mundo, rivais, sua reputação | [05](05-ECONOMY-DESIGN.md), [07](07-NPC-AI-ARCHITECTURE.md) |
| **Imobiliária** | Buscar/gerir imóveis | [08-Assets](08-ASSETS-SYSTEMS.md) |
| **Agenda** | O Daily Loop: tempo, compromissos, eventos | [03-Gameplay](03-GAMEPLAY-DESIGN.md) §2.2 |
| **Mapa** | Navegação, oportunidades, pontos de interesse | [04-World](04-WORLD-DESIGN.md) |

> O smartphone resolve a tensão central: dá acesso rápido a sistemas profundos **sem quebrar a imersão**, porque olhar o celular *é* uma ação crível de um empresário.

### 3.2 Os Consultores-IA (a interface humana para a complexidade)
Em vez de despejar dados, MOGUL usa **personagens-conselheiros** (agentes — [07](07-NPC-AI-ARCHITECTURE.md)) como camada de UX:
- **CFO-IA** — traduz finanças: *"O fluxo de caixa aperta no mês que vem por causa daquele recebível atrasado. Sugiro adiar a contratação ou puxar a linha de crédito."*
- **Consultor de estratégia** — lê o mercado e sugere movimentos.
- **Headhunter / RH-IA** — sobre talento e clima.
- **Broker / Advisor** — sobre investimentos e M&A.

> Você contrata e melhora esses conselheiros (melhores conselheiros = melhor "UI", insights mais profundos). A **qualidade da sua informação vira progressão de jogo** — uma forma elegante de gating de complexidade que serve o Pilar III.

## 4. Os Fluxos de UX Principais (UX Flows)

Cada fluxo segue o mandamento: **toda ação significativa é uma cena vivida, não um clique de menu.**

### 4.1 Fluxo: Contratar um funcionário
```
Identificar necessidade (CFO/RH-IA sinaliza ou jogador decide)
  → Abrir vagas / acionar headhunter (MeridianOS)
  → Receber candidatos (agentes gerados/recrutados)
  → ENTREVISTA (cena diegética): conversar, ler sinais, avaliar fit
  → Negociar oferta (salário, equity, condições) — minigame social
  → Decisão → Onboarding → o NPC aparece fisicamente no escritório
```
Contraste com o anti-padrão: *não* é "abrir menu → arrastar funcionário → confirmar".

### 4.2 Fluxo: Fechar um deal / negociação
```
Contexto (reunião marcada / encontro de networking)
  → CENA de negociação (frente a frente com o agente)
  → Leitura: humor, interesse, alternativas do outro lado (info revelada por relação)
  → Trocas: propor termos, blefar, ceder, pressionar (modulado por skills + status + reputação)
  → Acordo / impasse → consequência registrada na memória do agente ([07])
```

### 4.3 Fluxo: Fundar uma empresa
```
Detectar oportunidade (mercado/insight)
  → Escolher nicho ([06] §3) → definir nome, marca, posicionamento
  → Capital (próprio/crédito/sócio) → registrar
  → Espaço físico (mesa em casa → coworking → sala) ([08])
  → Primeira contratação / primeiro cliente → empresa "nasce" no mundo
```

### 4.4 Fluxo: Aquisição (M&A) — campanha multi-etapa
Resumido em [06-Business](06-BUSINESS-SYSTEMS.md) §6.1; em UX é uma **sequência de cenas** (due diligence → negociação/cerco → fechamento → integração), não uma transação instantânea.

### 4.5 Fluxo: O Daily Loop
```
Acordar (no seu imóvel atual — status visível) → checar MeridianOS (mensagens/news/mercado)
  → revisar Agenda → sair para o mundo → executar blocos do dia
  → eventos imprevistos (chamadas, encontros) → fechar o dia (descanso/lazer/trabalho extra)
```

## 5. HUD & Feedback no Mundo

- **HUD minimalista e contextual:** aparece só quando relevante (objetivo atual, prompt de interação, alertas urgentes); some para maximizar imersão. Toggle de "cinematic/minimal HUD".
- **Feedback diegético de eventos:** uma manchete na tela do celular, uma ligação, a reação facial (MetaHuman) de um NPC — o mundo *te conta* o que importa.
- **Notificações priorizadas:** o sistema filtra ruído; só interrompe o jogador por coisas que exigem atenção pessoal (a essência da "economia da atenção", [03](03-GAMEPLAY-DESIGN.md) §8).
- **Marcadores de conquista:** marcos (1º milhão, 1ª aquisição, entrada no Apex Club) recebem tratamento cinematográfico — momentos, não pop-ups (serve a cláusula "conquista visível", [01](01-PRODUCT-VISION.md)).

## 6. Legibilidade de Causa & Efeito (o "por quê")

Para uma simulação profunda ser justa, o jogador precisa entender consequências. MOGUL garante isso via:
- **"Por quê?" rastreável:** em qualquer métrica/evento, o jogador pode pedir a explicação (o consultor-IA narra a cadeia causal: *"vendas caíram → porque um rival baixou preços → porque captou investimento mês passado"*).
- **Timeline de eventos:** um registro diegético (feed de notícias + histórico pessoal) que conta a história do seu império e do mundo.
- **Pré-visualização de impacto:** decisões importantes mostram consequências prováveis antes de confirmar (sem remover risco/incerteza — mostra *faixas*, não certezas).

## 7. Acessibilidade & Conforto

MOGUL é projetado para acessibilidade de padrão AAA (requisito, não opcional):
- **Visão:** escalonamento de texto, alto contraste, daltonismo (paletas), leitor de tela para UI crítica, legendas completas + closed captions para áudio ambiente.
- **Motora:** remapeamento total, modos de input simplificado, redução de ações por tempo, sem QTEs punitivos.
- **Cognitiva (crucial dada a profundidade):** "modo guiado" com consultores-IA mais proativos, glossário diegético contextual, tutoriais sob demanda, ritmo ajustável (pausar o tempo a qualquer momento fora de cenas).
- **Conforto:** opções de motion blur/câmera, sem-flash, gerenciamento de intensidade.
- **Profundidade ajustável:** os sliders de simulação ([03](03-GAMEPLAY-DESIGN.md) §7) são também acessibilidade — permitem ao jogador escolher seu nível de complexidade.

## 8. Direção de Arte de UI

- **Linguagem visual:** premium, limpa, "fintech de luxo encontra editorial de revista de negócios". Tipografia forte, espaço negativo, micro-animações satisfatórias, materiais (vidro, metal, ouro como acento).
- **Evolução com a fantasia:** a própria UI **amadurece** com o jogador — o MeridianOS na Fase 1 é básico; na Fase 5, é um cockpit de comando de império, refletindo a ascensão.
- **Identidade sonora:** UX sound design premium (cada interação tem um som "caro" e satisfatório — parte da fantasia de luxo).
- **Captura/replay:** ferramentas de foto/clip de qualidade (serve a persona criador de conteúdo — [02-Market](02-MARKET-ANALYSIS.md) — e o marketing orgânico).

---

> **Anterior:** [← 08 — Assets Systems](08-ASSETS-SYSTEMS.md) · **Próximo:** [10 — Technical Architecture →](10-TECHNICAL-ARCHITECTURE.md)

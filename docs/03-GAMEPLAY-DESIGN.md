# 03 — Gameplay Design: Core Loops, Meta Loops & Progression

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 03 de 12 · Confidencial

---

## 1. Filosofia de Loop

MOGUL é uma cebola de loops aninhados. Cada loop alimenta o de cima. O jogador deve sentir progresso em **todas** as escalas de tempo simultaneamente — do minuto à década.

```
┌──────────────────────────────────────────────────────────────┐
│ LEGACY LOOP (décadas de jogo / múltiplos playthroughs)         │
│  ┌────────────────────────────────────────────────────────┐  │
│  │ EMPIRE META-LOOP (anos de jogo)                          │  │
│  │  ┌──────────────────────────────────────────────────┐  │  │
│  │  │ BUSINESS LOOP (semanas/meses de jogo)              │  │  │
│  │  │  ┌────────────────────────────────────────────┐  │  │  │
│  │  │  │ DAILY LOOP (minutos a horas / 1 dia de jogo) │  │  │  │
│  │  │  │  ┌──────────────────────────────────────┐  │  │  │  │
│  │  │  │  │ MOMENT LOOP (segundos: a interação)   │  │  │  │  │
│  │  │  │  └──────────────────────────────────────┘  │  │  │  │
│  │  │  └────────────────────────────────────────────┘  │  │  │
│  │  └──────────────────────────────────────────────────┘  │  │
│  └────────────────────────────────────────────────────────┘  │
└──────────────────────────────────────────────────────────────┘
```

## 2. Os Cinco Loops Detalhados

### 2.1 Moment Loop (segundos) — "A Interação"
A unidade atômica de MOGUL. Toda a fantasia se reduz, no menor nível, a **interações significativas**: uma conversa, uma negociação, uma decisão, uma observação.

`Perceber → Avaliar → Agir → Reagir (o mundo responde) → Consequência imediata`

Exemplos: ler a linguagem corporal de um candidato; decidir se aceita uma contraproposta; reparar que um rival entrou no restaurante; clicar "comprar" numa ação em queda. **Requisito:** toda interação deve ter feedback imediato, legível e com peso (áudio, animação, reação do NPC).

### 2.2 Daily Loop (um dia de jogo) — "A Vida"
O ritmo da vida do empresário. Tempo e energia são recursos. O jogador gerencia uma agenda.

`Acordar → Checar estado (negócios, mensagens, mercado, mundo) → Planejar o dia → Executar atividades (trabalho / reuniões / networking / pessoal) → Eventos imprevistos → Dormir / fechar o dia`

- **Recursos do dia:** Tempo (blocos de agenda), Energia/Foco (esgota com atividade, recupera com descanso/lazer — afeta saúde de longo prazo), Atenção (quantas frentes você pode tocar pessoalmente).
- **Tensão central:** você nunca tem tempo para tudo. Delegar (confiar em gerentes-IA) vs. fazer pessoalmente (mais controle, mais desgaste) é a escolha-mãe do jogo. Conforme você escala, **delegar bem** torna-se a meta-habilidade.

### 2.3 Business Loop (semanas/meses) — "A Operação"
O ciclo de fazer um negócio crescer.

`Detectar oportunidade/demanda → Alocar capital + pessoas → Produzir/Entregar → Vender (clientes-IA) → Faturar → Reinvestir / extrair → Medir → Ajustar estratégia`

- Cada empresa roda esse loop continuamente (simulado mesmo offline para o jogador — ver [05-Economy](05-ECONOMY-DESIGN.md) e [06-Business](06-BUSINESS-SYSTEMS.md)).
- O jogador intervém nos **pontos de alavancagem**: contratação-chave, decisão de preço, expansão, crise.

### 2.4 Empire Meta-Loop (anos) — "O Império"
O ciclo de transformar empresas em um império.

`Consolidar empresa → Gerar excedente de capital → Buscar próxima fronteira (novo setor / aquisição / mercado) → Adquirir/Fundar → Integrar (sinergias, org) → Aumentar influência/reputação → Desbloquear novas fronteiras`

- É aqui que vivem **M&A, holdings, IPOs, expansão geográfica, diversificação setorial** (ver [06](06-BUSINESS-SYSTEMS.md)).
- O loop é alimentado por **reputação e relações** (networking de elite abre portas que dinheiro não abre).

### 2.5 Legacy Loop (décadas / playthroughs) — "O Legado"
O endgame e a rejogabilidade.

`Atingir influência global → Definir legado (filantropia / instituições / dinastia) → Formar sucessor → Transferir → Novo início com herança (New Game+ geracional)`

- O objetivo final **não é dinheiro — é influência e permanência** (ver §6 Endgame).

## 3. As Cinco Fases Emocionais (gating de mecânicas)

As fases de [01-Vision](01-PRODUCT-VISION.md) são também a **estrutura de onboarding progressivo**: cada fase introduz mecânicas, evitando sobrecarga cognitiva. A progressão entre fases é **orgânica** (dirigida por marcos), não por níveis numéricos explícitos.

| Fase | Mecânicas introduzidas | Mecânicas trancadas (ainda) | "North Star" da fase |
|------|------------------------|------------------------------|----------------------|
| **1. Sobrevivência** | Vida pessoal, tempo/energia, freelancing, networking básico, finanças pessoais | Funcionários, escritórios, investimento, M&A | Sair do vermelho; fundar a 1ª empresa |
| **2. Crescimento** | Contratar, escritório físico, clientes, marketing, crédito | M&A, holdings, IPO, mercado de capitais | 1ª rodada de investimento |
| **3. Escala** | Gerentes, delegação, múltiplas empresas, holding, sinergias, sócios | IPO, manipulação de mercado, política | 1ª aquisição relevante |
| **4. Influência** | RP/mídia, IPO, mercado de capitais avançado, eventos de elite, lobby indireto | Sucessão/legado | Mover o mercado; figura pública |
| **5. Legado** | Filantropia, instituições, fundações, sucessão, New Game+ | — | Definir e cimentar o legado |

> **Design de tutorial:** a Fase 1 *é* o tutorial — sem "tutorial" explícito. O jogador aprende a viver antes de aprender a gerir. Onboarding diegético via um NPC mentor opcional e via a própria pressão da sobrevivência. (Ver [09-UX-UI](09-UX-UI.md).)

## 4. Progressão de Personagem (o avatar)

O jogador é uma **pessoa**, não uma corporação. A progressão pessoal é tão importante quanto a empresarial. (Sem "níveis de RPG" explícitos; progressão é diegética e sistêmica.)

### 4.1 Atributos pessoais (eixos de competência)
Crescem com uso/prática e via educação/mentoria. Afetam a eficácia de ações:

| Atributo | Afeta |
|----------|-------|
| **Negociação** | Resultados de deals, salários, contratos, M&A |
| **Carisma / Presença** | Networking, RP, liderança, fechamento de vendas |
| **Acumen Financeiro** | Qualidade de análise de investimentos, leitura de mercado, due diligence |
| **Visão Estratégica** | Qualidade das "dicas" e previsões que o jogo te dá; antecipar tendências |
| **Liderança** | Produtividade/lealdade de funcionários, retenção, cultura |
| **Resiliência** | Resistência a estresse, recuperação de fracassos, saúde mental |
| **Especialidades setoriais** | Bônus por domínio (ex.: "Tech", "Imobiliário", "Finanças") |

### 4.2 Recursos pessoais (estado momento-a-momento)
- **Saúde física** — afetada por estresse, sono, alimentação, exercício; consequências de longo prazo (eventos médicos) se negligenciada.
- **Saúde mental / Estresse** — alta pressão sem descompressão gera burnout (penalidades, eventos negativos).
- **Energia/Foco** — recurso diário (ver Daily Loop).
- **Tempo** — o recurso mais escasso; a economia central do jogo é a **economia da atenção do jogador**.
- **Felicidade / Realização** — métrica pessoal que tensiona contra a ganância (você pode ser bilionário e miserável — e o jogo *mostra* isso).

> **Tensão de design intencional:** o jogo te empurra a sacrificar saúde/relações/felicidade por crescimento. Mas as consequências disso são reais e visíveis. MOGUL não diz "isso é errado" — ele **mostra o custo** e deixa o jogador escolher que tipo de magnata quer ser.

### 4.3 Habilidades & estilo de jogo (arquétipos emergentes)
Não há "classes". O estilo emerge de como o jogador investe atributos e tempo. Arquétipos que o sistema reconhece e premia diferentemente:

- **The Operator** — mestre em eficiência operacional e margens.
- **The Dealmaker** — vive de M&A, negociação, networking.
- **The Visionary** — aposta em setores emergentes, alto risco/retorno.
- **The Shark** — aquisições hostis, alavancagem, jogo agressivo.
- **The Statesman** — reputação, influência, filantropia, jogo longo.

## 5. Estilos de Vitória (múltiplas fantasias de poder)

MOGUL não tem uma "tela de vitória". Tem **estados aspiracionais** que o jogador persegue (ver Endgame em [01-Vision](01-PRODUCT-VISION.md) §3 e §6 aqui):

- **Magnata setorial** — dominar um setor inteiro.
- **Investidor global / Shark investor** — viver de capital, não de operar.
- **Dono de holding multinacional** — um conglomerado diversificado e global.
- **Filantropo / Statesman** — converter capital em influência e legado.
- **Figura pública mundial** — máxima fama/influência, mover mercados com palavras.

Cada estilo tem sua própria progressão, recompensas visíveis e endgame.

## 6. Endgame & Meta-Progressão

> **O objetivo final não é dinheiro. É influência e permanência.**

Dinheiro é **meio**, não fim. Acima de certo patamar, mais dinheiro tem utilidade marginal decrescente *por design* — o jogo desloca a meta para:

- **Influência** — capacidade de mover mercados, moldar a cidade, afetar políticas (indiretamente), definir tendências.
- **Prestígio/Legado** — instituições com seu nome, fundações, obras, reconhecimento histórico.
- **Sucessão** — formar um herdeiro/sucessor (NPC ou avatar de New Game+) e transferir o império.

### 6.1 Sistemas de endgame
- **Holding global & conglomerado** — gerir um portfólio massivo via gerentes-IA de altíssimo nível.
- **Influência sistêmica** — "alavancas" macro (ver [05-Economy](05-ECONOMY-DESIGN.md)) que só os maiores players acessam.
- **Filantropia & instituições** — converter capital em reputação/legado permanente; universidades, hospitais, prêmios, fundos.
- **Dinastia / Sucessão** — formar sucessor; o legado define os **bônus de início** do próximo personagem.

### 6.2 New Game+ Geracional (rejogabilidade de longo prazo)
Ao "passar o bastão", o jogador inicia um novo personagem (filho/protegido/nova geração) que **herda** parte do mundo modificado: reputação da família, ativos selecionados, contatos, e um mundo que *lembra* do magnata anterior. Cada geração é uma nova run com vantagens herdadas e um mundo permanentemente marcado pelas runs anteriores — a fonte primária de rejogabilidade de centenas de horas.

## 7. Onboarding & Curva de Dificuldade

- **Primeiros 30 min ("o gancho"):** estabelecer a fantasia (caminhar pela cidade desejável), a tensão (a conta vencendo), e a primeira vitória (o primeiro freela/cliente). O jogador deve terminar a primeira sessão *querendo voltar*.
- **Curva:** sobrevivência tensa mas justa → crescimento recompensador → escala empoderadora → influência inebriante → legado reflexivo.
- **Dificuldade:** sliders de simulação (rigor econômico, agressividade dos rivais, punição de fracasso) + presets ("Story/Casual", "Tycoon/Balanced", "Mogul/Hardcore", "Iron Boardroom/permadeath de empresa").
- **Acessibilidade de profundidade:** "assistentes" diegéticos (consultores-IA, CFO, advisors) que explicam sistemas sob demanda, permitindo que o jogador escolha sua profundidade de engajamento (ver [09-UX-UI](09-UX-UI.md)).

## 8. Economia da Atenção do Jogador (o meta-recurso)

O recurso mais escasso de MOGUL não é dinheiro — é a **atenção/tempo do jogador**. Todo o jogo é uma alocação dessa atenção:

- Cedo: o jogador faz quase tudo pessoalmente (alta imersão, baixo escopo).
- Tarde: o jogador comanda um império vasto demais para tocar pessoalmente; **delegar para gerentes-IA confiáveis** é a habilidade-mestra do endgame.
- O design garante que **delegar nunca seja "deixar de jogar"** — o jogador troca o jogo de "operar" pelo jogo de "governar, escolher pessoas e definir estratégia". A natureza do gameplay *evolui* com a escala.

> Este é o mecanismo que mantém o jogo divertido tanto na Fase 1 (você varre o chão) quanto na Fase 5 (você decide o futuro de uma indústria) — sem que nenhuma das duas vire tédio.

---

> **Anterior:** [← 02 — Market Analysis](02-MARKET-ANALYSIS.md) · **Próximo:** [04 — World Design →](04-WORLD-DESIGN.md)

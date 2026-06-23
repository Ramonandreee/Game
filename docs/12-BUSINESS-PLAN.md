# 12 — Business Plan & Live Operations

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 12 de 12 · Confidencial
> *Inclui: Revenue Model, Monetization, Risk Analysis, Post-Launch Plan, Expansion Packs, DLC Strategy, Five-Year Product Vision*

---

## 1. Filosofia de Negócio

> **MOGUL é um produto premium e um serviço de longo prazo — mas nunca um jogo predatório. A monetização segue a mesma regra do design: ela só existe se *aumentar* a fantasia de império, nunca se a explorar.**

Três princípios:
1. **Premium primeiro, serviço depois.** O jogador paga por um jogo completo e excelente. A camada de serviço é *aditiva e opcional*, não um pré-requisito para se divertir.
2. **Nada de pay-to-win.** Um jogo *sobre* construir um império por mérito não pode vender o império. Monetização pós-venda é **cosmética, de conveniência e de conteúdo (expansões)** — nunca vantagem competitiva.
3. **LTV via amor, não via vício.** O modelo de DLC da Paradox/Cities prova: jogadores que amam um sim profundo compram conteúdo por **anos**. O moat é a profundidade, não dark patterns.

## 2. Revenue Model

### 2.1 Fontes de receita (camadas)
| Camada | O quê | Tipo | Quando |
|--------|-------|------|--------|
| **Base game** | Jogo premium completo | One-time (USD 69,99) | Lançamento |
| **Edições especiais** | Deluxe/Collector (cosméticos, season pass, early access) | One-time premium | Lançamento |
| **Expansões** | Grandes pacotes (novos setores, cidades, mecânicas) | Pago (~USD 25–40) | 2/ano pós-lançamento |
| **DLC menor / Content Packs** | Pacotes temáticos focados | Pago (~USD 8–15) | Frequente |
| **Cosméticos** | Imóveis, veículos, roupas, arte de escritório, skins de marca | Microtransação (não-P2W) | Loja rotativa |
| **MOGUL+ (assinatura opcional)** | Saves expandidos, mundos online persistentes, perks cosméticos, acesso antecipado | Recorrente (opcional) | Pós-lançamento |
| **Creator economy (longo prazo)** | UGC marketplace com revenue share | Take rate | Visão 5 anos |

### 2.2 Por que esse mix
- **Premium** captura o valor da experiência AAA e estabelece a marca como "jogo de respeito" (anti-mobile-tycoon).
- **Expansões** são o motor de LTV: cada novo *setor* ou *cidade* reabre o jogo para o jogador (e gera pico de vendas + reengajamento).
- **Cosméticos** monetizam o desejo de *status/expressão* — perfeitamente alinhado com a fantasia (ver [08-Assets](08-ASSETS-SYSTEMS.md)) — sem desbalancear.
- **Assinatura opcional** suaviza receita e financia o custo operacional contínuo (incl. inferência de IA — §6).

## 3. Projeções Financeiras

> *Cenários de pré-produção. Premissas: preço base USD 69,99 (receita líquida por unidade ~USD 45–50 após plataforma/varejo); mercado de "AAA novo IP de categoria nova".*

### 3.1 Cenários de vendas (ano 1)
| Cenário | Cópias ano 1 | Receita bruta base game ano 1 | + DLC/cosm. ano 1 |
|---------|-------------|-------------------------------|-------------------|
| **Conservador** | 3,5M | ~USD 175M | ~USD 55M |
| **Base** | 6,0M | ~USD 300M | ~USD 100M |
| **Otimista** | 12,0M | ~USD 600M | ~USD 200M |

### 3.2 Visão de 5 anos (receita acumulada — cenário base)
| Fonte | 5 anos (cenário base) |
|-------|------------------------|
| Base game (vendas contínuas + edições) | ~USD 550M |
| Expansões (10 grandes ao longo de 5 anos) | ~USD 300M |
| DLC menor + cosméticos | ~USD 180M |
| Assinatura MOGUL+ | ~USD 90M |
| **Total 5 anos** | **~USD 1,1B** |

### 3.3 Break-even & ROI
- **Investimento total:** ~USD 285M (produção ~195M + marketing ~90M — [11](11-PRODUCTION-PLAN.md)).
- **Break-even:** ~2,8–3,4M cópias equivalentes (incl. DLC) — **atingível no ano 1 no cenário base e até no conservador**.
- **ROI 5 anos (base):** ~3,8x. **(Otimista):** >7x.

### 3.4 Unit economics & custo de IA (a variável crítica)
- **Risco de margem:** inferência de LLM cloud tem **custo marginal por jogador** — diferente de jogos tradicionais. Não gerido, isso pode corroer a margem.
- **Mitigação (arquitetura — [10](10-TECHNICAL-ARCHITECTURE.md) §5):**
  - Preferência por **SLM on-device** (custo marginal ≈ 0).
  - Cloud LLM só em "momentos importantes", com **orçamento de tokens por sessão** e caching.
  - Fallback determinístico (custo 0) sempre disponível.
  - **MOGUL+** ajuda a cobrir o custo de jogadores "heavy AI".
- **Meta:** custo de IA por jogador/mês mantido numa fração pequena da receita média por usuário, monitorado como KPI de margem desde o beta.

## 4. Go-To-Market & Marketing (~USD 90M)

- **Posicionamento:** "The AAA Life-Business Sim" — criar a categoria ([02-Market](02-MARKET-ANALYSIS.md)). Âncoras: *"o GTA dos negócios"*, *"The Sims para quem quer poder de verdade"*.
- **Vetor #1 — Criadores de conteúdo:** o jogo é projetado para gerar histórias clipáveis ([07-AI](07-NPC-AI-ARCHITECTURE.md) §7). Programa robusto com streamers/YouTubers de games, business e finanças (audiência cruzada única). Este é o canal de maior ROI.
- **Vetor #2 — Beta/Early Access:** comunidade pré-lançamento, telemetria, e prova social ([11](11-PRODUCTION-PLAN.md) §7).
- **Vetor #3 — Beats de marca:** reveal cinematográfico, gameplay deep-dives (vender a profundidade), o Vertical Slice como demo pública.
- **Vetor #4 — Cultura de negócios/finanças:** parcerias e PR fora do nicho gamer (a fantasia tem alcance mainstream).
- **Curva:** awareness (reveal) → desejo (gameplay/criadores) → conversão (beta + lançamento) → retenção (Live Ops).

<a id="risk-analysis"></a>
## 5. Risk Analysis

> Matriz de riscos do projeto. Severidade × Probabilidade × Mitigação. (Resumos em vários docs apontam para cá.)

### 5.1 Riscos de produto/design
| # | Risco | Sev. | Prob. | Mitigação |
|---|-------|------|-------|-----------|
| R1 | **Feature creep / escopo** — o projeto colapsa sob sua própria ambição | **Crítica** | Alta | Pillar gate ([01](01-PRODUCT-VISION.md) §5); gates de fase ([11](11-PRODUCTION-PLAN.md)); VS como contrato; cortar sem dó |
| R2 | **A simulação econômica não é divertida** ("fun-finding") | Crítica | Média | Protótipo econômico no Ano 1 (paper+digital); sim acelerada para tuning; legibilidade ([09](09-UX-UI.md)) |
| R3 | **A complexidade afasta jogadores** (curva brutal) | Alta | Média | Progressão de profundidade; consultores-IA; sliders; Fase 1 como tutorial ([03](03-GAMEPLAY-DESIGN.md), [09](09-UX-UI.md)) |
| R4 | **A fantasia "viver, não gerenciar" não se concretiza** | Alta | Média | "Feel prototype" no Ano 1; playtest emocional contínuo |

### 5.2 Riscos técnicos
| # | Risco | Sev. | Prob. | Mitigação |
|---|-------|------|-------|-----------|
| R5 | **Custo/latência/qualidade de LLM inviabiliza os agentes** | Alta | Média | Arquitetura híbrida (on-device+cloud+fallback); IA como enhancement, não dependência ([07](07-NPC-AI-ARCHITECTURE.md) §4, [10](10-TECHNICAL-ARCHITECTURE.md) §5) |
| R6 | **Performance** — densidade + agentes + sim não cabem no console (esp. Series S) | Alta | Média | LOD triplo (geo/sim/cognição); budget por distrito; regeneração determinística ([10](10-TECHNICAL-ARCHITECTURE.md)) |
| R7 | **Saves enormes/corrompidos** em runs de centenas de horas | Média | Média | Compactação de memória; regeneração por seed; serialização versionada; saves atômicos ([10](10-TECHNICAL-ARCHITECTURE.md) §7) |
| R8 | **Custo operacional de IA corrói margem** | Alta | Média | Unit economics §3.4; on-device first; MOGUL+; KPI de margem |

### 5.3 Riscos de mercado/negócio
| # | Risco | Sev. | Prob. | Mitigação |
|---|-------|------|-------|-----------|
| R9 | **Educar uma categoria nova é caro/lento** | Média | Média | Âncoras de comparação; marketing de fantasia; criadores de conteúdo ([02](02-MARKET-ANALYSIS.md)) |
| R10 | **Incumbente (EA/Paradox/Rockstar) entra no espaço** | Média | Baixa-Média | Vantagem de pioneirismo; moat de integração+dados; velocidade |
| R11 | **Backlash a IA generativa** (percepção) | Média | Média | Transparência; "NPCs com mente" (valor real, não gimmick); opt-out determinístico; guard-rails ([10](10-TECHNICAL-ARCHITECTURE.md) §11) |
| R12 | **Janela de lançamento lotada / fadiga AAA** | Média | Média | Flexibilidade de data; beta para fidelizar cedo; diferenciação clara |

### 5.4 Riscos de execução/organização
| # | Risco | Sev. | Prob. | Mitigação |
|---|-------|------|-------|-----------|
| R13 | **Crunch/burnout** destrói o time | Alta | Média | Gates realistas; co-dev para carga; cultura sustentável ([11](11-PRODUCTION-PLAN.md)) |
| R14 | **Slip de cronograma** (custo ~25–30M/6 meses no pico) | Alta | Média | De-risk early; produção incremental; contingência 10–15% |
| R15 | **Dependência de talento escasso** (IA + UE5 sênior) | Média | Média | Recrutamento antecipado; parcerias; documentação/processos |

## 6. Post-Launch Plan (Live Operations)

> O lançamento é o **começo**, não o fim. MOGUL é um serviço de longo prazo (modelo Paradox/CDPR: o jogo de 5 anos depois é muito maior que o de lançamento).

### 6.1 Cadência de Live Ops
- **Patches de estabilidade** (semanas 1–8): qualidade pós-lançamento massivo.
- **Updates gratuitos regulares:** balanceamento (economia data-driven — [10](10-TECHNICAL-ARCHITECTURE.md)), quality-of-life, eventos sazonais de mundo, conteúdo cosmético rotativo, e **novas features gratuitas** para manter a base engajada e a boa vontade alta.
- **Expansões pagas:** ~2 grandes por ano (§7).
- **Temporadas online:** ciclos para a camada online assíncrona ([10](10-TECHNICAL-ARCHITECTURE.md) §6.2) com leaderboards e recompensas cosméticas.
- **Loop data-driven:** telemetria → priorização → conteúdo/balanceamento → deploy (muito via backend, sem patch de cliente).

### 6.2 Community & retenção
- **Roadmap público** e comunicação transparente (estilo dev-diary Paradox).
- **Programa de criadores** contínuo.
- **Modding/UGC** crescente (ver §9 — visão de 5 anos).

## 7. Expansion Packs & DLC Strategy

### 7.1 Filosofia de DLC
DLC **expande a fantasia**, nunca a recorta para revender. Três tamanhos:
- **Expansões maiores (Expansions):** abrem novas dimensões de jogo — um novo *setor* profundo, uma nova *cidade* (via o aeroporto — [04-World](04-WORLD-DESIGN.md) §3.7), ou uma nova *mecânica-pilar*. ~USD 25–40.
- **Content Packs:** temáticos e focados (um pacote de luxo, um pacote de uma indústria específica, eventos). ~USD 8–15.
- **Cosmetic Packs / loja:** imóveis, veículos, roupas, arte (não-P2W — §2). Microtransação.

### 7.2 Pipeline de expansões (exemplos — roadmap plurianual)
| Onda | Tema (exemplos) | Tipo |
|------|------------------|------|
| **Ano 1 pós** | "Wall Street" (mercado de capitais aprofundado), "Industry Titan" (manufatura/cadeia global) | Expansões |
| **Ano 2 pós** | "Go Global: Nova Cidade #1" (expansão internacional jogável), "Media Mogul" (mídia/entretenimento/influência) | Expansões |
| **Ano 3 pós** | "Dynasty" (sucessão/legado geracional aprofundado), "Green Empire" (energia/ESG/sustentabilidade) | Expansões |
| **Contínuo** | Pacotes setoriais, sazonais, cosméticos, eventos | Content/Cosmetic Packs |

> Cada nova **cidade** é o maior multiplicador de LTV: reabre o mundo inteiro, gera pico de vendas e reengajamento — e a arquitetura modular de Meridian + o aeroporto-portal foram desenhados exatamente para isso ([04-World](04-WORLD-DESIGN.md), [10](10-TECHNICAL-ARCHITECTURE.md)).

## 8. KPIs & Métricas de Sucesso (Live)
- **Aquisição:** unidades vendidas, CAC, conversão de wishlist/beta.
- **Engajamento:** DAU/MAU, sessões, tempo de sessão, profundidade de progressão (quantos chegam à Fase 4–5), retenção D1/D7/D30/D90.
- **Monetização:** ARPU/ARPPU, attach rate de DLC, conversão de MOGUL+, LTV.
- **Margem:** **custo de IA por usuário** (KPI crítico — §3.4), custo de infra/usuário.
- **Saúde do produto:** sentiment/review score, churn, NPS, histórias emergentes compartilhadas (proxy do moat).

## 9. Five-Year Product Vision

> **A ambição não é lançar um jogo. É criar — e ser dono de — uma categoria e uma plataforma.**

### Fase A — Estabelecer (Ano 1 pós-lançamento)
Provar o serviço: estabilizar, entregar as primeiras grandes expansões, consolidar a comunidade, validar unit economics de IA. **Meta:** MOGUL reconhecido como *o* AAA life-business sim.

### Fase B — Expandir (Anos 2–3 pós)
- **Go Global:** novas cidades jogáveis (Meridian vira a primeira de um *mundo*).
- **Aprofundar pilares:** mídia/influência, dinastia/legado, energia/ESG.
- **Camada online madura:** mundos compartilhados, temporadas, coop — a dimensão social como segundo motor de retenção.
- **Plataformas:** cloud, próxima geração de consoles.

### Fase C — Plataformizar (Anos 4–5 pós)
- **Creator Economy / UGC:** ferramentas para a comunidade criar nichos, cenários, conteúdo — com **marketplace e revenue share**. O conteúdo passa a escalar para além do estúdio (o efeito-rede que torna o moat permanente — [02-Market](02-MARKET-ANALYSIS.md)).
- **MOGUL como marca/IP:** potencial transmídia (a fantasia de magnata tem alcance além do jogo); franquia de longo prazo.
- **A simulação como ativo:** a stack de agentes + economia é, ela mesma, tecnologia valiosa e reusável (sequências, novos títulos, licenciamento).

### A estrela-guia de 5 anos
> Que, daqui a cinco anos, **"jogar MOGUL"** seja sinônimo da fantasia de construir um império — como *The Sims* é sinônimo de simular uma vida — sustentado por uma comunidade que cria, compete e compartilha histórias que nenhum outro jogo consegue gerar.

---

> **Anterior:** [← 11 — Production Plan](11-PRODUCTION-PLAN.md) · **Voltar ao índice:** [README](../README.md)

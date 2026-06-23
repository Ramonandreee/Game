# 11 — Production Plan

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 11 de 12 · Confidencial
> *Inclui: Development Roadmap, Vertical Slice, MVP, Full Production, Team Structure, Budget Forecast*

---

## 1. Filosofia de Produção

> **Um projeto desta ambição morre por escopo, não por falta de ideias. A produção é desenhada em torno de uma única disciplina: provar a diversão antes de escalar a produção.**

Três regras de ouro:
1. **De-risk early.** Os maiores riscos (economia divertida? agentes críveis a custo viável? a fantasia funciona?) são atacados **primeiro**, em protótipos baratos, antes do investimento pesado.
2. **Vertical slice é um contrato.** O slice define o padrão de qualidade e prova o pilar. Nada entra em produção em massa antes de o slice provar o conceito.
3. **Pillar gate em todo greenlight.** Toda feature passa pelo gate de [01-Vision](01-PRODUCT-VISION.md) §5. É a principal defesa contra feature creep ([12-Risk](12-BUSINESS-PLAN.md)).

## 2. Visão Geral do Roadmap (~6 anos)

```
ANO 1        ANO 2         ANO 3         ANO 4         ANO 5         ANO 6
│Concept &   │ Pré-prod /  │ Produção    │ Produção     │ Produção    │ Lançamento
│Prototype   │ Vertical    │ (ramp-up)   │ (full)       │ (content    │ & Live Ops
│            │ Slice       │ → MVP       │              │ complete) → │
│            │             │             │              │ Alpha/Beta  │ → GA
└─PROTO──────┴─VS─────────┴─MVP─────────┴─PRODUCTION──┴─POLISH/BETA─┴─SHIP──►
   ▲ Gate 1     ▲ Gate 2      ▲ Gate 3      ▲ Gate 4      ▲ Gate 5      ▲ Launch
```

| Marco | Quando | Gate de decisão |
|-------|--------|-----------------|
| **Concept Complete** | Fim Ano 1 (mês ~12) | A fantasia + economia se provam jogáveis? (go/no-go de pré-prod) |
| **Vertical Slice** | Mês ~18 | Qualidade AAA provada num fatia? (go/no-go de produção) |
| **MVP / First Playable completo** | Mês ~36 | O loop completo do início ao fim é divertido? (go para full content) |
| **Content Complete / Alpha** | Mês ~54 | Todo o conteúdo presente, jogável ponta-a-ponta |
| **Beta** | Mês ~60 | Estável, em polimento, beta pública/early access |
| **Gold / Launch** | Mês ~66–72 (T4 2032) | Pronto para ship |

## 3. Fase 1 — Concept & Prototype (Ano 1)

**Objetivo:** provar (ou refutar) as três apostas de maior risco *antes* de montar um time grande.

### 3.1 Workstreams de protótipo (paralelos)
- **Economy Prototype** — modelo econômico jogável (primeiro em *planilha/paper*, depois sim digital headless e protótipo jogável simples). Mitiga o risco "fun-finding" ([12-Risk](12-BUSINESS-PLAN.md)). **Entregável: a economia é divertida e estável por décadas simuladas.**
- **Agent AI Prototype** — agentes Tier 2/3 com memória + Big Five + diálogo híbrido, provando **credibilidade a custo/latência viáveis** ([07](07-NPC-AI-ARCHITECTURE.md), [10](10-TECHNICAL-ARCHITECTURE.md)). **Entregável: um NPC que lembra de você e parece vivo, dentro do budget de custo.**
- **"Feel" Prototype (fantasia)** — um quarteirão jogável de Meridian: caminhar, entrar num café, ter um encontro de networking, fechar um micro-deal. Prova o Pilar I. **Entregável: playtesters dizem "senti que era um empresário".**
- **Tech Spike** — World Partition + Mass Entity + MetaHuman em escala; provar densidade urbana com agentes.

### 3.2 Equipe (Ano 1): pequena e sênior
~25–40 pessoas: direção (creative/game/tech/art), um time de design de sistemas, um time de IA/engenharia core, um pequeno time de arte/tech-art, produção. **Sêniores fazendo protótipos baratos** — sem produção de massa ainda.

**Gate 1 (Concept Complete):** se as três apostas se provam, avança para pré-produção. Se a economia ou os agentes não convencem, **pivota ou cancela barato** — a decisão mais importante do projeto.

## 4. Fase 2 — Pré-Produção & Vertical Slice (Ano 2)

**Objetivo:** produzir uma **fatia vertical de qualidade de lançamento** que prove o jogo inteiro em microcosmo.

### 4.1 Definição do Vertical Slice (o contrato de qualidade)
Uma experiência curta (~30–60 min) mas **com acabamento de lançamento**, demonstrando *todos os pilares*:

- **Um pedaço de Meridian** (1–2 distritos, ex.: The Grid + parte dos Boroughs) com acabamento final (Nanite/Lumen, densidade, interiores).
- **A fantasia ponta-a-ponta em pequena escala:** começar pequeno → 1º freela → fundar 1ª empresa → 1ª contratação (entrevista diegética) → 1º cliente → um encontro de networking que importa.
- **Agentes de verdade:** ~3–5 NPCs Tier 3 com memória e diálogo híbrido funcionando; multidão Mass Entity ao redor.
- **Economia real (slice):** um setor funcionando com oferta/demanda e ao menos um rival-IA agindo.
- **UX diegética:** MeridianOS + um consultor-IA + uma cena de negociação polida.
- **Um "momento épico":** um marco com tratamento cinematográfico (ex.: assinar o primeiro grande contrato).

> **O slice é o pitch jogável** para o publisher/investidores e o **benchmark de qualidade** para toda a produção. É também o principal artefato de marketing inicial.

### 4.2 Equipe (Ano 2): ~80–120
Crescimento dos times de design, arte, engenharia, IA, áudio, UX; início de pipelines de produção e ferramentas. Definição de processos, padrões de qualidade e "definition of done".

**Gate 2 (Vertical Slice):** qualidade AAA comprovada e fantasia validada → **greenlight de produção plena**. Este é o gate em que o orçamento principal é comprometido.

## 5. Fase 3 — Produção: Ramp-up até MVP (Ano 3)

**Objetivo:** construir o **esqueleto completo e jogável** do jogo — o loop inteiro das 5 fases existe, mesmo que com conteúdo parcial.

### 5.1 Definição do MVP / First Playable Completo
Diferente do Vertical Slice (profundidade num ponto), o **MVP prova a amplitude**: o jogador consegue ir da **Fase 1 (Sobrevivência) à Fase 5 (Legado)** de ponta a ponta, com todos os sistemas core presentes (mesmo que com conteúdo reduzido e arte parcial em áreas).

- **Cidade:** todos os 6 distritos presentes (parte com arte de produção, parte com whitebox/proto).
- **Sistemas core completos:** economia, empresas (fundar/operar/M&A), agentes/networking/reputação, imóveis/veículos, finanças, save.
- **Conteúdo "tracer bullet":** ao menos alguns nichos por setor; um conjunto de agentes; eventos principais.
- **Jogável de cabo a rabo:** uma "run" completa é possível (mesmo que ~10–20h em vez das centenas finais).

**Gate 3 (MVP):** o jogo completo **é divertido** do começo ao fim? → **greenlight de conteúdo em massa**. Se a curva longa não engaja, ajusta-se design antes de produzir todo o conteúdo (de-risk).

### 5.2 Equipe (Ano 3): ~180–250 (ramp-up)
Times de produção de conteúdo em escala (mundo, agentes, nichos, missões/eventos), QA estruturado, live-ops/backend começando, ferramentas maduras.

## 6. Fase 4 — Produção Plena (Ano 4)

**Objetivo:** **produção de conteúdo em massa** sobre o esqueleto provado.

- **Mundo:** Meridian completa, todos os distritos com arte final, densidade-alvo, interiores.
- **Conteúdo:** todos os setores/nichos do lançamento ([06](06-BUSINESS-SYSTEMS.md) §3.1); biblioteca completa de agentes-template; catálogos (imóveis/veículos/roupas/arte); eventos de mundo; narrativa/tutorial diegético; missões/arcos de "tempero".
- **Sistemas:** features secundárias, polimento de IA, balanceamento econômico contínuo (sim acelerada — [10](10-TECHNICAL-ARCHITECTURE.md) §4).
- **Online:** backend e camada online assíncrona em desenvolvimento ([10](10-TECHNICAL-ARCHITECTURE.md) §6).

### 6.1 Equipe (Ano 4): ~350–450 (pico)
Pico de headcount, incluindo **co-desenvolvimento externo** (outsourcing de arte/ambientes/animação) sob direção interna. Produção paralela em múltiplas frentes (strike teams por sistema/distrito).

## 7. Fase 5 — Content Complete, Alpha, Beta & Polish (Ano 5)

- **Alpha (Content Complete):** todas as features e conteúdo presentes; jogável ponta-a-ponta; foco em bugs e tuning.
- **Beta / Early Access (opcional, estratégico):** estabilidade; **beta pública/early access** para coletar telemetria em escala, balancear a economia com dados reais e construir comunidade pré-lançamento ([12](12-BUSINESS-PLAN.md) — também de-risk de mercado).
- **Polish & Optimization:** performance por plataforma (incl. Series S), acessibilidade, áudio, "game feel", momentos épicos.
- **Certificação:** submissão a plataformas (PlayStation/Xbox/Steam/Epic), classificação etária (ESRB/PEGI), conformidade.
- **Balanceamento data-driven:** loop intenso de telemetria → ajuste → re-deploy (a economia e a IA são afinadas com dados reais).

### 7.1 Equipe (Ano 5): ~350 → desmobilização gradual
Pico de QA e balanceamento; arte começa a desmobilizar; engenharia foca em otimização/estabilidade; cresce o time de Live Ops/community.

## 8. Fase 6 — Launch & Transição para Live Ops (Ano 6)

- **Lançamento (T4 2032):** ship multiplataforma. War room de lançamento.
- **Day-1/Day-30 patches:** estabilidade e ajustes pós-lançamento massivo.
- **Transição para Live Ops:** o time central remanescente vira o time de serviço (ver [12-Business](12-BUSINESS-PLAN.md) para roadmap pós-lançamento).

## 9. Estrutura de Equipe (Team Structure)

### 9.1 Disciplinas e proporção aproximada (no pico)
| Disciplina | % aprox. | Notas |
|------------|---------|-------|
| **Arte & Animação** | ~30% | Mundo, personagens (MetaHuman), veículos, UI art; maior co-dev externo |
| **Engenharia** | ~22% | Core systems, economy engine, IA, tools, backend, plataforma |
| **Design** | ~14% | Systems, economy, content, narrative, level/world, UX design |
| **QA** | ~12% | Funcional, sim/economia, compliance, automação |
| **IA/ML especializada** | ~5% | Agentes, LLM ops, knowledge graph, balanceamento por ML |
| **Áudio** | ~4% | Música, SFX, VO, MetaSounds |
| **Produção** | ~6% | Produtores, leads de projeto, planejamento |
| **Tech Art / Tools** | ~4% | Pipeline, PCG, performance |
| **Live Ops/Backend/Data** | ~3% (crescente) | Cresce rumo ao lançamento |

### 9.2 Estrutura organizacional
- **Liderança:** Game Director, Creative Director, Technical Director, Art Director, Audio Director, Executive Producer.
- **Strike teams (feature teams) multidisciplinares** por domínio: *World*, *Economy & Business*, *Agents & AI*, *Player & Progression*, *UX/UI*, *Online/Live*, *Content*. Cada um com leads de cada disciplina.
- **Pillars guardians:** um pequeno grupo (direção) que guarda os pilares e opera o pillar gate ([01-Vision](01-PRODUCT-VISION.md) §5).
- **Co-dev externo** sob direção interna para escalar arte/animação/QA.

## 10. Orçamento de Produção (Budget Forecast)

> *Estimativa de pré-produção em ordens de grandeza. Total de **produção ~USD 195M** ao longo de ~6 anos (excl. marketing — ver [12](12-BUSINESS-PLAN.md)).*

### 10.1 Custo por ano (curva de ramp)
| Ano | Fase | Headcount médio | Custo aprox. (USD) |
|-----|------|-----------------|--------------------|
| 1 | Concept/Proto | ~30 | ~10M |
| 2 | Pré-prod/VS | ~100 | ~22M |
| 3 | Prod ramp/MVP | ~210 | ~38M |
| 4 | Full production | ~420 | ~55M |
| 5 | Alpha/Beta/Polish | ~350 | ~48M |
| 6 | Launch/transição | ~200 (decrescente) | ~22M |
| | **Total produção** | | **~195M** |

### 10.2 Distribuição por categoria (do total de produção)
| Categoria | % aprox. | USD aprox. |
|-----------|---------|-----------|
| Pessoal (salários, benefícios) | ~62% | ~121M |
| Co-desenvolvimento / outsourcing | ~14% | ~27M |
| Tech (engine royalties, middleware, ferramentas) | ~5% | ~10M |
| **Infra cloud + custo de IA/LLM (dev + parte operacional)** | ~7% | ~14M |
| QA / certificação / localização | ~6% | ~12M |
| Overhead (instalações, admin, legal) | ~6% | ~11M |
| Contingência | — | (reservada à parte, ~10–15%) |

> **Nota de IA:** o custo *operacional* de inferência LLM no pós-lançamento (escala com a base de jogadores) é tratado no [12-Business](12-BUSINESS-PLAN.md) (unit economics) e mitigado pela arquitetura híbrida/on-device ([10](10-TECHNICAL-ARCHITECTURE.md) §5). Aqui contabiliza-se o custo de desenvolvimento e a reserva inicial de operação.

### 10.3 Premissas e sensibilidade
- Custos de pessoal dominam; a maior alavanca de custo é **headcount × duração** — daí a disciplina de gates (cada slip de cronograma é caro).
- Marketing (~USD 90M) e contingência são tratados separadamente ([12](12-BUSINESS-PLAN.md)).
- Sensibilidade-chave: um atraso de 6 meses no pico (~Ano 4) custa na ordem de ~USD 25–30M — reforçando por que **de-risk early** é uma estratégia *financeira*, não só de produção.

## 11. Riscos de Produção (resumo; matriz completa em [12](12-BUSINESS-PLAN.md))
| Risco | Mitigação de produção |
|-------|----------------------|
| Escopo/feature creep | Pillar gate; gates de fase; VS como contrato |
| Economia não diverte | Protótipo no Ano 1; sim acelerada para tuning |
| IA inviável (custo/qualidade) | Protótipo no Ano 1; arquitetura híbrida; IA como enhancement |
| Performance em consoles | Budgets por distrito; LOD triplo; Series S como limite de design |
| Burnout/crunch | Planejamento realista; gates evitam "death march"; co-dev para carga |

---

> **Anterior:** [← 10 — Technical Architecture](10-TECHNICAL-ARCHITECTURE.md) · **Próximo:** [12 — Business Plan & Live Operations →](12-BUSINESS-PLAN.md)

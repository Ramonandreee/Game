# 05 — Economy & Financial Systems

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 05 de 12 · Confidencial

---

## 1. Filosofia Econômica

> **A economia de MOGUL é um organismo, não um placar. Ela tem ciclos, humores e memória — e nunca está esperando o jogador.**

Três princípios governam o design econômico:

1. **Simulação, não scripting.** Preços, demanda e ciclos *emergem* de oferta, demanda e do comportamento de milhares de agentes (consumidores-IA, empresas-IA). Não são tabelas roteirizadas.
2. **Legível apesar de profunda.** A economia é complexa por baixo, mas o jogo *sempre explica* por que algo aconteceu (um analista-IA traduz: "as vendas caíram porque o Banco Central subiu os juros e o crédito secou"). Profundidade sem legibilidade é frustração (ver [01-Vision](01-PRODUCT-VISION.md) §7).
3. **Camadas:** Macro (a economia do país/cidade) → Setorial (cada indústria) → Empresarial (suas empresas) → Pessoal (seu bolso). Cada camada influencia a de baixo.

## 2. Arquitetura Econômica em Camadas

```
┌─────────────────────────────────────────────────────────────┐
│ CAMADA MACRO  — Banco Central, PIB, inflação, juros, crédito │
│   ↓ influencia                                                │
│ CAMADA SETORIAL — oferta/demanda por nicho, ciclos, hype     │
│   ↓ influencia                                                │
│ CAMADA EMPRESARIAL — receita, custo, margem, fluxo de caixa  │
│   ↓ influencia                                                │
│ CAMADA PESSOAL — patrimônio, renda, dívida, gastos, status   │
└─────────────────────────────────────────────────────────────┘
        ↑ os agentes (consumidores + empresas-IA) fecham o loop ↑
```

## 3. Camada Macro — A Economia Viva

### 3.1 Variáveis macroeconômicas simuladas
Um **Banco Central de Meridian (NPC institucional)** e o agregado de agentes produzem:

| Variável | O que modela | Impacto no jogo |
|----------|--------------|-----------------|
| **PIB / Ciclo econômico** | Expansão ↔ recessão (ciclos) | Demanda agregada, otimismo, valuations |
| **Inflação** | Erosão do poder de compra | Custos sobem, preços de venda, salários, contratos indexados |
| **Taxa de juros (SELIC-análoga)** | Custo do dinheiro, definida pelo BC-IA | Custo de crédito, atratividade de investimento vs. renda fixa, valuations |
| **Crédito / liquidez** | Disponibilidade de financiamento | Facilidade de captar; "credit crunch" em crises |
| **Desemprego** | Folga no mercado de trabalho | Custo/disponibilidade de contratar talento |
| **Confiança (consumidor & empresarial)** | "Humor" da economia | Propensão a consumir e investir |
| **Câmbio** (pós-expansão global) | Valor da moeda local | Importação/exportação, operações internacionais |

### 3.2 O Banco Central como agente
O BC-IA persegue metas (controlar inflação, suavizar ciclos) e **reage** ao estado da economia ajustando juros — incluindo reagir a *ações de mega-players* (o jogador no endgame pode, com escala suficiente, influenciar indiretamente a política — ver §9). Suas decisões são **anunciadas pela mídia-IA**, criando antecipação e gameplay de timing.

### 3.3 Ciclos econômicos & choques
- **Ciclos endógenos:** boom → euforia/bolha → correção/recessão → recuperação, emergindo de crédito, confiança e comportamento de manada dos agentes.
- **Choques exógenos (eventos):** crises setoriais, "cisnes negros", booms de hype (ex.: uma nova tecnologia vira mania). Calibrados para acontecer com frequência que mantém o mundo imprevisível mas não caótico.
- **Bolhas:** setores podem inflar (hype + crédito barato) e estourar — punindo quem entrou tarde e premiando quem saiu a tempo. **Timing de ciclo é uma habilidade-mestra.**

## 4. Camada Setorial — Mercados por Nicho

Cada um dos **setores/nichos** (ver [06-Business](06-BUSINESS-SYSTEMS.md) §3) tem seu próprio submercado com dinâmica de **oferta × demanda**:

- **Demanda** por setor = f(PIB, confiança, demografia, modas/hype, sazonalidade, preço).
- **Oferta** = soma da capacidade de todos os players (jogador + empresas-IA).
- **Preço de equilíbrio** emerge; margens comprimem quando há excesso de oferta (muitos rivais entraram), expandem quando há escassez.
- **Ciclos setoriais:** cada setor tem seu próprio ciclo de hype/maturação/comoditização. Setores emergentes (alta margem, alto risco) → maduros (baixa margem, estável) → declinantes (consolidação).

> **Gameplay resultante:** detectar um setor antes do hype (alto retorno), evitar setores superlotados (margens mortas), e sair antes da comoditização. O mapa de setores é um tabuleiro dinâmico de oportunidades.

## 5. Os Agentes Econômicos (o que faz a economia *viver*)

A economia não é uma equação — é o **agregado de comportamentos de agentes** (ver [07-AI](07-NPC-AI-ARCHITECTURE.md)):

### 5.1 Consumidores-IA (a demanda)
A população de Meridian são consumidores com renda, preferências, e sensibilidade a preço/qualidade/marca/status. Eles **escolhem** de quem comprar (você ou um rival) com base em preço, qualidade, reputação de marca e conveniência. Modelados em escala via Mass Entity (agregados) + amostragem de agentes profundos.

### 5.2 Empresas-IA (a concorrência — ver [06](06-BUSINESS-SYSTEMS.md) §8)
Centenas de empresas controladas por IA que **operam de verdade**: contratam, demitem, investem, lançam produtos, sobem/baixam preços, expandem, fazem M&A, **falem** e **crescem** — tudo **sem depender do jogador**. Elas competem com você pelos mesmos consumidores, talentos e ativos.

### 5.3 Investidores-IA (o capital)
Anjos, VCs, fundos, bancos — agentes que **alocam capital** com base em risco/retorno, em você (sua reputação e track record) e na macro. Eles te procuram quando você está "quente" e somem quando o mercado vira.

> Esse trio (consumidores + empresas + investidores) fecha o loop econômico: a economia macro **emerge** de baixo para cima, não é imposta de cima.

## 6. Camada Empresarial — Finanças Corporativas

Cada empresa do jogador (ou IA) é uma entidade financeira simulada. Detalhes operacionais em [06-Business](06-BUSINESS-SYSTEMS.md); aqui, as finanças.

### 6.1 Demonstrativos (existem de verdade, mas apresentados diegéticamente)
- **DRE / Income Statement:** Receita − Custos (COGS, salários, marketing, overhead) = Lucro operacional → − juros − impostos = Lucro líquido.
- **Balanço / Balance Sheet:** Ativos (caixa, imóveis, equipamentos, estoque, participações) vs. Passivos (dívidas, contas a pagar) vs. Patrimônio.
- **Fluxo de Caixa / Cash Flow:** o **rei**. Empresas lucrativas no papel quebram por falta de caixa. Gerir o fluxo de caixa (timing de recebíveis vs. pagáveis) é tensão central, especialmente no crescimento.

> **Apresentação:** o jogador não "lê uma planilha" por padrão — um **CFO-IA** resume em linguagem natural e o jogador pode "abrir os números" quando quiser (profundidade opcional — ver [09-UX-UI](09-UX-UI.md)).

### 6.2 Valuation (quanto vale uma empresa)
Crucial para M&A, IPO, investimento e venda. Múltiplos métodos (o jogo usa um modelo híbrido, mostrado como "faixa de avaliação"):
- **Múltiplos** (sobre receita ou lucro, variando por setor e por ciclo de hype).
- **DCF-simplificado** (fluxo de caixa futuro descontado pela taxa de juros — por isso juros altos derrubam valuations).
- **Ativos líquidos** (piso de avaliação).
- **Prêmio estratégico** (sinergias para um comprador específico; o que viabiliza M&A lucrativo).

### 6.3 Financiamento (de onde vem o capital)
| Fonte | Quando | Custo/contrapartida |
|-------|--------|---------------------|
| **Bootstrapping / lucro retido** | Fase 1–2 | Sem diluição, lento |
| **Dívida (banco/linha de crédito)** | Fase 2+ | Juros (atrelados à macro), risco de inadimplência |
| **Investimento anjo** | Fase 2 | Diluição, mas traz mentor/contatos |
| **Venture Capital (seed/A/B/C)** | Fase 2–4 | Diluição + pressão por crescimento + assento no conselho |
| **Private Equity** | Fase 3–4 | Grande capital, controle, alavancagem |
| **IPO (abrir capital na MerEx)** | Fase 4 | Liquidez massiva, mas escrutínio público, mídia, voláteis acionistas |
| **Dívida corporativa / bonds** | Fase 4–5 | Captação em escala para conglomerados |

## 7. Camada Pessoal — Finanças do Avatar

O jogador é uma pessoa com finanças pessoais **separadas** das empresas (uma lição de design e de vida):

- **Patrimônio pessoal (net worth)** — a métrica de status #1, somando caixa, participações, imóveis, ativos de luxo.
- **Renda pessoal** — pró-labore, dividendos, ganhos de capital.
- **Gastos pessoais** — moradia, estilo de vida, status (carros, roupas — ver [08](08-ASSETS-SYSTEMS.md)). **Lifestyle creep** é uma armadilha real: subir o padrão de vida cedo demais pode quebrar você.
- **Dívida pessoal** — cartão, financiamentos; juros pessoais punitivos no início.
- **A "muralha" entre PJ e PF:** misturar finanças pessoais e da empresa é possível mas perigoso (risco legal/reputacional — ver [06](06-BUSINESS-SYSTEMS.md) e [07-Reputação](07-NPC-AI-ARCHITECTURE.md)).
- **Tela de "net worth" diegética:** seu patrimônio é visível e *sentido* — pelo bairro onde mora, pelo carro, por como NPCs te tratam.

## 8. Mercado de Capitais (a MerEx)

A **Meridian Exchange (MerEx)** é a bolsa de valores — um sistema de endgame (Fase 4–5):

- **Ações de empresas públicas** (suas, de rivais-IA, e "blue chips" do mundo) com preços que flutuam por desempenho, macro, e *sentimento* (mídia, boatos, manada).
- **Investir** em outras empresas (incl. comprar participações em rivais — gancho para aquisições).
- **Abrir seu capital (IPO)** — evento-marco com captação massiva e novas pressões.
- **Trading & especulação** — para o arquétipo "investidor"; renda passiva e risco.
- **Manipulação de mercado** (cinza/ilegal) — pump-and-dump, insider trading via networking — alto retorno, alto risco reputacional/legal (ver §10).
- **Derivativos e instrumentos avançados** (endgame): hedge, alavancagem, short selling (apostar contra rivais).

## 9. Alavancas de Influência Macro (Endgame)

> No endgame, o jogador deixa de ser *sujeito* da economia e passa a ser uma *força* dentro dela.

Players suficientemente grandes desbloqueiam **influência sistêmica**:
- **Mover mercados** com declarações públicas (sua palavra afeta preços — Fase 4+).
- **Lobby indireto** sobre políticas (regulação setorial, impostos, incentivos) via reputação governamental (ver [07-Reputação](07-NPC-AI-ARCHITECTURE.md)).
- **Influenciar o ciclo** — grandes movimentos de capital seu podem aquecer/esfriar setores.
- **Criar/quebrar tendências** — definir o que é "o próximo grande setor".

Isso materializa o endgame de **influência > dinheiro** ([03-Gameplay](03-GAMEPLAY-DESIGN.md) §6).

## 10. Risco, Crime Econômico & Consequência

A economia tem um **lado escuro** opcional, com risco real:
- **Sonegação / fraude contábil** — melhora números no curto prazo, risco de auditoria, multas, prisão, ruína reputacional.
- **Insider trading & manipulação** — lucros via informação privilegiada obtida por networking; risco de investigação.
- **Corrupção / suborno** — atalhos para licenças, contratos, regulação; risco de escândalo.
- **Calote / falência estratégica** — usar a falência como ferramenta (com custo reputacional e de relações).

> Coerente com o tom ([01-Vision](01-PRODUCT-VISION.md) §6): o jogo **não moraliza, mas há consequências reais e propagantes** (governo, mídia, parceiros). O "caminho sujo" é viável e tentador — e perigoso.

## 11. Balanceamento & Tuning

- **Data-driven:** todas as variáveis econômicas são expostas em tabelas de tuning (ver [10-Tech](10-TECHNICAL-ARCHITECTURE.md), data-driven design) para iteração rápida sem recompilar.
- **Modelo de fluxo de moeda (sources & sinks):** mapeado explicitamente para evitar hiperinflação ou deflação no save de longo prazo (impostos, custos, depreciação e lifestyle são os principais *sinks*).
- **Simulação acelerada para QA:** ferramenta de "fast-forward" que roda anos de economia em segundos para detectar instabilidades e desequilíbrios (ver [11-Production](11-PRODUCTION-PLAN.md)).
- **Sliders de jogador:** rigor econômico ajustável (Casual → Hardcore), conforme [03-Gameplay](03-GAMEPLAY-DESIGN.md) §7.
- **Protótipo econômico no Ano 1:** mitigação do risco "fun-finding" — a economia é prototipada (paper + sim digital) antes do investimento pesado de produção (ver [11](11-PRODUCTION-PLAN.md), [12-Risk](12-BUSINESS-PLAN.md)).

---

> **Anterior:** [← 04 — World Design](04-WORLD-DESIGN.md) · **Próximo:** [06 — Business & Corporate Growth →](06-BUSINESS-SYSTEMS.md)

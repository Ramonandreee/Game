# MOGUL
### *A Business Empire Life Simulator*

> **Codinome de produção:** Project ATLAS
> **Tagline:** *"Você não administra um império. Você vive um."*
> **Documento:** Bíblia de Pré-Produção — v1.0 (Confidencial)
> **Data:** Junho de 2026
> **Status:** Concept Complete → Pré-Produção

---

## 🎮 Jogar agora (protótipo jogável)

Já existe um **protótipo jogável** da fatia vertical — o "feel + economy prototype" do Ano 1 do [plano de produção](docs/11-PRODUCTION-PLAN.md). Roda no navegador, **sem instalar nada**:

> **▶ Abra [`game/index.html`](game/index.html) no seu navegador** (baixe o arquivo e dê duplo-clique, ou abra direto).

O que dá para fazer agora: começar falido nos Boroughs, sobreviver de freelas, **fundar empresas** (10 setores, cada um com economia própria), **contratar agentes** com personalidade que pedem aumento / abrem concorrentes, **fazer networking** (café → coworking → Apex Club), enfrentar uma **economia viva** (ciclos de boom/recessão, juros), comprar **status** (apartamento, carro) que muda como o mundo te trata, e subir as **5 fases** de Sobrevivência a Legado. Salva automático. Veja [`game/README.md`](game/README.md) para detalhes.

*A economia foi balanceada por simulação headless (centenas de dias simulados) e as rotas de UI validadas por testes automatizados — conforme a disciplina de [de-risk early](docs/11-PRODUCTION-PLAN.md).*

---

## O que é MOGUL

**MOGUL** é um simulador de vida empresarial em mundo aberto, single-player no núcleo e com uma camada online persistente, construído na **Unreal Engine 5.6**. O jogador não opera planilhas: ele encarna um ser humano que parte de um apartamento minúsculo e de um computador velho e, ao longo de décadas de tempo de jogo, ascende — ou fracassa — na tentativa de construir um império de negócios em **Meridian City**, uma metrópole global viva.

A fantasia central não é "ganhar dinheiro". É **sentir a ascensão**: a primeira contratação, o primeiro escritório, a primeira aquisição hostil, a primeira capa de revista, a primeira fundação filantrópica, o primeiro herdeiro. Cada conquista é **visível no mundo**. Cada erro gera **consequências persistentes**.

MOGUL combina três pilares de gênero que nunca foram fundidos nesta escala:

1. **Open-World Life Sim** (densidade urbana e presença física à la Rockstar/CDPR).
2. **Deep Business/Economy Simulation** (profundidade sistêmica à la Paradox).
3. **Agentic NPCs** (NPCs movidos por agentes de IA com memória, personalidade e objetivos próprios — à la Larian em consequência, mas dinâmicos).

---

## Mapa da Bíblia de Pré-Produção

Esta especificação é organizada como um documento interno de estúdio AAA. Cada arquivo é autossuficiente e cruza referências com os demais.

### Parte I — Visão & Estratégia
| # | Documento | Cobre |
|---|-----------|-------|
| 00 | [Executive Summary](docs/00-EXECUTIVE-SUMMARY.md) | Sumário executivo, pitch, números-chave |
| 01 | [Product Vision & Core Pillars](docs/01-PRODUCT-VISION.md) | Visão de produto, pilares de design, princípio de design |
| 02 | [Market, Audience & Competition](docs/02-MARKET-ANALYSIS.md) | Público-alvo, análise de mercado, concorrentes, USP |

### Parte II — Game Design
| # | Documento | Cobre |
|---|-----------|-------|
| 03 | [Gameplay & Meta Loops](docs/03-GAMEPLAY-DESIGN.md) | Core loops, meta loops, fases emocionais, progressão de personagem |
| 04 | [World Design](docs/04-WORLD-DESIGN.md) | Meridian City, distritos, densidade, ciclo de vida urbano |
| 05 | [Economy & Financial Systems](docs/05-ECONOMY-DESIGN.md) | Macroeconomia, mercados, finanças corporativas e pessoais |
| 06 | [Business & Corporate Growth Systems](docs/06-BUSINESS-SYSTEMS.md) | Empresas, segmentos, M&A, funcionários, conglomerados |
| 07 | [NPC & Agent AI Architecture](docs/07-NPC-AI-ARCHITECTURE.md) | Agentes, memória, personalidade, networking, reputação |
| 08 | [Real Estate & Vehicle Systems](docs/08-ASSETS-SYSTEMS.md) | Imóveis, construção, veículos, status físico |

### Parte III — Experiência & Tecnologia
| # | Documento | Cobre |
|---|-----------|-------|
| 09 | [UX/UI Design](docs/09-UX-UI.md) | Filosofia de interface diegética, fluxos de UX, acessibilidade |
| 10 | [Technical Architecture](docs/10-TECHNICAL-ARCHITECTURE.md) | Engine, dados, backend, multiplayer, save, content pipeline, escalabilidade |

### Parte IV — Produção & Negócio
| # | Documento | Cobre |
|---|-----------|-------|
| 11 | [Production Plan](docs/11-PRODUCTION-PLAN.md) | Roadmap, vertical slice, MVP, full production, equipe, orçamento |
| 12 | [Business Plan & Live Operations](docs/12-BUSINESS-PLAN.md) | Modelo de receita, monetização, risco, pós-lançamento, DLC, visão de 5 anos |

> Documentos de apoio: [Glossário](docs/GLOSSARY.md) · [Changelog](docs/CHANGELOG.md)

---

## Fatos canônicos do projeto (Single Source of Truth)

Todos os documentos derivam destes fatos. Alterações aqui propagam para toda a bíblia.

| Campo | Valor |
|-------|-------|
| **Título** | MOGUL |
| **Subtítulo** | A Business Empire Life Simulator |
| **Codinome** | Project ATLAS |
| **Gênero** | Open-World Business Life Simulation RPG |
| **Engine** | Unreal Engine 5.6 |
| **Plataformas (lançamento)** | PC (Steam/Epic), PlayStation 5 / 5 Pro, Xbox Series X\|S |
| **Plataformas (pós)** | Cloud streaming, plataforma de geração seguinte |
| **Modos** | Single-player (núcleo) + Persistent Online Layer (assíncrono/coop) |
| **Cenário** | Meridian City — metrópole global fictícia |
| **Modelo de negócio** | Premium (USD 69,99) + Expansões + Cosméticos + Serviços online |
| **Orçamento de produção** | ~USD 195M |
| **Orçamento de marketing/lançamento** | ~USD 90M |
| **Pico de equipe** | ~450 pessoas (interno + externo) |
| **Duração de produção** | ~6 anos (concept → launch) |
| **Janela de lançamento alvo** | T4 2032 |
| **Classificação alvo** | ESRB Mature 17+ / PEGI 18 |
| **Idiomas no lançamento** | 12 (full VO em 6) |

---

## Os Três Pilares (resumo)

1. **"Viva o Império"** — Tudo é diegético, físico e visível. Sem planilhas frias; cada número tem um corpo no mundo.
2. **"O Mundo Reage"** — Uma economia e uma sociedade de agentes que existem com ou sem o jogador. Ações têm consequências persistentes e propagantes.
3. **"Da Sobrevivência ao Legado"** — Uma curva de fantasia de poder que vai do apartamento apertado ao conglomerado multinacional e à sucessão.

> **Princípio de Design Mestre:** Todo sistema precisa responder *"Isso faz o jogador sentir que está construindo um império?"*. Se a resposta for não, o sistema é cortado.

---

## Como ler esta bíblia

- **Investidores / Publishers:** comece em [00-Executive-Summary](docs/00-EXECUTIVE-SUMMARY.md) → [02-Market](docs/02-MARKET-ANALYSIS.md) → [12-Business-Plan](docs/12-BUSINESS-PLAN.md).
- **Direção criativa / Design:** [01-Vision](docs/01-PRODUCT-VISION.md) → [03 a 08].
- **Engenharia / Tech:** [10-Technical-Architecture](docs/10-TECHNICAL-ARCHITECTURE.md) → [07-AI](docs/07-NPC-AI-ARCHITECTURE.md) → [05-Economy](docs/05-ECONOMY-DESIGN.md).
- **Produção:** [11-Production-Plan](docs/11-PRODUCTION-PLAN.md).

---

*Documento confidencial. Distribuição restrita a stakeholders autorizados do Project ATLAS.*

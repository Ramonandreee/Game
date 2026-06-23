# Glossário — Project ATLAS / MOGUL

> Termos canônicos da bíblia de pré-produção. Mantém a consistência entre documentos.

## Projeto & Mundo
| Termo | Definição |
|-------|-----------|
| **MOGUL** | Título do jogo. *A Business Empire Life Simulator.* |
| **Project ATLAS** | Codinome interno de produção. |
| **Meridian City** | A metrópole global fictícia onde o jogo se passa. Ver [04-World](04-WORLD-DESIGN.md). |
| **Sterling Heights** | Distrito Financeiro. |
| **The Grid** | Distrito Tecnológico. |
| **Ironside Docklands** | Distrito Industrial/portuário. |
| **The Boroughs** | Distrito Residencial (onde o jogador começa). |
| **Goldhaven** | Distrito de Luxo. |
| **MER / Meridian International** | Aeroporto internacional; portal para expansão global. |
| **MerEx** | Meridian Exchange — a bolsa de valores. |
| **Apex Club** | Clube de elite em Goldhaven; símbolo-meta de chegada ao topo. |

## Design
| Termo | Definição |
|-------|-----------|
| **Pillar Gate** | Filtro de greenlight: *"isso faz o jogador sentir que está construindo um império?"*. Ver [01-Vision](01-PRODUCT-VISION.md) §5. |
| **As 5 Fases** | Sobrevivência → Crescimento → Escala → Influência → Legado. A curva emocional central. |
| **Diegese / Interface diegética** | Informação/ação que vive no mundo da ficção, não em menus abstratos. Pilar I. |
| **Loop** | Ciclo de gameplay. Moment → Daily → Business → Empire → Legacy. Ver [03](03-GAMEPLAY-DESIGN.md). |
| **Status Percebido** | Score social que agentes leem (endereço, veículo, roupa, reputação). Ver [08](08-ASSETS-SYSTEMS.md) §5. |
| **New Game+ Geracional** | Rejogabilidade via sucessão: novo personagem herda parte do mundo. |

## IA & Simulação
| Termo | Definição |
|-------|-----------|
| **Agente** | NPC de nova geração com perfil, personalidade (Big Five), memória e objetivos. Ver [07](07-NPC-AI-ARCHITECTURE.md). |
| **Tier 0–3** | Níveis de profundidade cognitiva de NPC (ambiental → protagonista). LOD de cognição. |
| **Big Five / OCEAN** | Modelo de personalidade (Openness, Conscientiousness, Extraversion, Agreeableness, Neuroticism). |
| **Knowledge Graph** | Grafo de memória/conhecimento por agente; base da memória persistente. |
| **Grafo Social** | Rede global de relações entre jogador, agentes e empresas. |
| **GOAP** | Goal-Oriented Action Planning — planejamento de ações por objetivo. |
| **Utility AI** | Tomada de decisão por pontuação de utilidade de ações. |
| **Híbrido (diálogo)** | Cascata templated → SLM local → LLM cloud → fallback. Ver [07](07-NPC-AI-ARCHITECTURE.md) §4. |
| **SLM / LLM** | Small/Large Language Model. On-device vs. cloud. |
| **RAG** | Retrieval-Augmented Generation — injetar contexto recuperado (memórias/fatos) no prompt. |
| **Grounding** | Ancorar a geração no estado real do jogo (anti-alucinação). |
| **Empresa-IA** | Concorrente autônomo controlado por IA. Ver [06](06-BUSINESS-SYSTEMS.md) §8. |

## Economia & Negócios
| Termo | Definição |
|-------|-----------|
| **Economy Engine** | Subsistema proprietário que simula a macro/setorial/empresarial. Ver [05](05-ECONOMY-DESIGN.md), [10](10-TECHNICAL-ARCHITECTURE.md). |
| **Nicho** | Unidade de negócio jogável com mecânica própria. Centenas no jogo. Ver [06](06-BUSINESS-SYSTEMS.md) §3. |
| **M&A** | Mergers & Acquisitions — fusões e aquisições. |
| **Due Diligence** | Investigação do valor/risco real de um alvo de aquisição. |
| **Valuation** | Avaliação de quanto vale uma empresa. |
| **IPO** | Initial Public Offering — abrir capital na MerEx. |
| **Sinergia** | Valor extra de combinar empresas (vertical/horizontal/capital/dados). |
| **Sink / Source** | Sumidouro / fonte de moeda no modelo econômico. |
| **Net Worth** | Patrimônio líquido pessoal — métrica de status #1. |

## Tecnologia
| Termo | Definição |
|-------|-----------|
| **UE5.6** | Unreal Engine 5.6 — engine do projeto. |
| **World Partition** | Sistema de streaming de mundo aberto da UE5. |
| **Nanite** | Geometria virtualizada (detalhe massivo sem LOD manual). |
| **Lumen** | Iluminação global dinâmica. |
| **Mass Entity** | Framework ECS da UE5 para multidões/simulação em escala. |
| **GAS** | Gameplay Ability System. |
| **PCG** | Procedural Content Generation framework. |
| **MetaHuman** | Sistema de humanos digitais realistas. |
| **EDA** | Event-Driven Architecture. |
| **LOD de Simulação** | Fidelidade variável de simulação por proximidade/relevância. Ver [10](10-TECHNICAL-ARCHITECTURE.md) §3.1. |
| **Regeneração determinística** | Recriar conteúdo por seed em vez de salvá-lo (economia de save). |

## Produção & Negócio
| Termo | Definição |
|-------|-----------|
| **Vertical Slice (VS)** | Fatia curta com qualidade de lançamento; prova os pilares. Ver [11](11-PRODUCTION-PLAN.md) §4. |
| **MVP** | Esqueleto jogável ponta-a-ponta (Fase 1 → 5). Ver [11](11-PRODUCTION-PLAN.md) §5. |
| **Gate** | Ponto de decisão go/no-go entre fases de produção. |
| **Strike Team** | Time multidisciplinar por domínio (World, Economy, Agents, etc.). |
| **Live Ops** | Operação contínua do jogo como serviço pós-lançamento. |
| **MOGUL+** | Assinatura opcional. Ver [12](12-BUSINESS-PLAN.md) §2. |
| **LTV / ARPU / CAC** | Lifetime Value / Average Revenue Per User / Customer Acquisition Cost. |
| **P2W** | Pay-to-Win — explicitamente **proibido** no design de monetização. |
| **Unit economics de IA** | Custo marginal de inferência por jogador; KPI de margem crítico. Ver [12](12-BUSINESS-PLAN.md) §3.4. |

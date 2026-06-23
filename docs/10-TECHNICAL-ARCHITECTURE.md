# 10 — Technical Architecture

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 10 de 12 · Confidencial
> *Inclui: Engine, Database, Backend, Multiplayer, Agent AI tech, Save System, Content Pipeline, Scalability*

---

## 1. Princípios Arquiteturais

1. **Data-driven em tudo.** Nichos, economia, agentes, conteúdo — definidos por dados (não código), para iteração rápida e expansibilidade via Live Ops ([12](12-BUSINESS-PLAN.md)).
2. **Simulação desacoplada da renderização.** A simulação do mundo (economia, agentes) roda como sistemas que **não dependem** de o jogador estar olhando — o mundo vive offscreen (Pilar II).
3. **LOD em todas as dimensões.** Não só geometria — **LOD de simulação** e **LOD de cognição** ([07-AI](07-NPC-AI-ARCHITECTURE.md)): gastamos custo onde o jogador está.
4. **Event-Driven Architecture (EDA).** Sistemas comunicam por eventos, não por chamadas diretas — desacoplamento, escalabilidade, e rastreabilidade (alimenta a legibilidade de causa/efeito — [09-UX](09-UX-UI.md) §6).
5. **IA como enhancement, não dependência crítica.** O jogo é 100% jogável sem a camada LLM ([07](07-NPC-AI-ARCHITECTURE.md) §4.2). Degradação graciosa.
6. **Offline-first no single-player.** O núcleo não exige conexão; a camada online é aditiva.

## 2. Engine & Stack Tecnológica (Unreal Engine 5.6)

| Tecnologia UE5 | Uso em MOGUL | Doc relacionado |
|----------------|--------------|-----------------|
| **World Partition** | Streaming da cidade aberta (Meridian) sem loadings; carregamento por distrito | [04-World](04-WORLD-DESIGN.md) |
| **Nanite** | Geometria massiva (skyline, interiores detalhados) sem custo de LOD manual | [04](04-WORLD-DESIGN.md), [08](08-ASSETS-SYSTEMS.md) |
| **Lumen** | Iluminação global dinâmica (ciclo dia/noite, interiores, clima) | [04-World](04-WORLD-DESIGN.md) §5 |
| **Mass Entity (ECS)** | Multidões e tráfego em escala (Tier 0/1 de agentes); simulação de população | [07-AI](07-NPC-AI-ARCHITECTURE.md) §2 |
| **GAS (Gameplay Ability System)** | Ações/habilidades do avatar e efeitos sistêmicos modulares | [03-Gameplay](03-GAMEPLAY-DESIGN.md) §4 |
| **PCG Framework** | Geração procedural de quarteirões, interiores, variação urbana | [04-World](04-WORLD-DESIGN.md) §7 |
| **MetaHuman** | Criação/variação de humanos críveis em escala (agentes Tier 2/3) | [07-AI](07-NPC-AI-ARCHITECTURE.md) §3 |
| **Chaos / Niagara** | Física e VFX (construção, ambiente, eventos) | [04](04-WORLD-DESIGN.md) |
| **MetaSounds** | Áudio procedural e UX sonora premium | [09-UX](09-UX-UI.md) §8 |

- **Linguagens:** C++ (sistemas core, performance), Blueprints (prototipagem, lógica de gameplay de alto nível, designers), Python (tooling/pipeline).
- **Custom systems sobre a engine:** o **Economy Engine**, o **Agent Simulation System** e o **Social/Knowledge Graph** são subsistemas proprietários construídos sobre a UE5 (ver §3–§5) — é onde está o moat técnico.

## 3. O Simulation Core (a "world tick")

O coração técnico: um **motor de simulação determinístico e desacoplado** que avança o mundo (economia + agentes) independentemente da renderização.

```
                  ┌──────────────────────────────────────┐
                  │          SIMULATION CORE              │
                  │  (roda em ticks lógicos, multi-thread) │
                  ├──────────────────────────────────────┤
   Game Time ───► │  Economy Engine  ──┐                  │
                  │  Agent Sim System ─┼─► EVENT BUS ◄────┼──► UI / World (render)
                  │  Company Sim ──────┘   (EDA)          │
                  │  Social/Knowledge Graph               │
                  └──────────────────────────────────────┘
                            │ persiste em ▼
                  ┌──────────────────────────────────────┐
                  │ SAVE / WORLD STATE (ver §7)           │
                  └──────────────────────────────────────┘
```

### 3.1 LOD de Simulação (como o mundo escala)
O mundo é vasto demais para simular tudo em alta fidelidade a cada tick. Solução em anéis de proximidade/relevância:

| Anel | Escopo | Fidelidade de simulação | Frequência de tick |
|------|--------|--------------------------|--------------------|
| **Foco** | Onde o jogador está + suas empresas-chave | Total (agentes Tier 2/3, economia detalhada) | Alta (tempo real) |
| **Próximo** | Distrito atual, contatos ativos, rivais relevantes | Média (decisões periódicas) | Média |
| **Distante** | Resto da cidade, empresas-IA não-relevantes | Abstrata (modelos agregados/estatísticos) | Baixa (batch) |
| **Dormente** | Mundo offscreen de longo prazo | Aproximação macro (sem agentes individuais) | Muito baixa / sob demanda |

> **Promoção/rebaixamento dinâmico:** quando o jogador interage com algo "distante", ele é *hidratado* para alta fidelidade just-in-time (mesma filosofia dos tiers de agentes — [07](07-NPC-AI-ARCHITECTURE.md) §2). Garante que "o mundo viva" sem custo impossível.

### 3.2 Event-Driven Architecture (EDA)
- **Event Bus** central: ações geram eventos (`EmployeeResigned`, `CompanyAcquired`, `MarketCrash`, `ScandalLeaked`).
- Sistemas **assinam** eventos relevantes e reagem (a mídia-IA assina escândalos; reputações assinam ações; rivais assinam movimentos do jogador).
- Benefícios: desacoplamento, extensibilidade (DLC adiciona listeners sem tocar o core), e um **log de eventos** que alimenta a timeline diegética e a legibilidade causal ([09-UX](09-UX-UI.md) §6).

## 4. Economy Engine (detalhe técnico)

Implementa o modelo de [05-Economy](05-ECONOMY-DESIGN.md):
- **Resolução de mercados** por setor (oferta/demanda → preço de equilíbrio) em batch a cada "tick econômico" (ex.: diário/semanal de jogo).
- **Agregação bottom-up:** demanda emerge de consumidores-IA (amostragem estatística + agentes profundos onde relevante), não de tabelas fixas.
- **Modelo macro** (PIB, juros, inflação, crédito) como sistema de equações + agente Banco Central, alimentado pelo agregado.
- **Data-driven tuning:** todos os parâmetros em data tables/DataAssets, hot-reload para balanceamento ([05](05-ECONOMY-DESIGN.md) §11).
- **Simulação acelerada ("headless econ sim")** para QA: roda anos de economia sem render, para caçar instabilidades ([11-Production](11-PRODUCTION-PLAN.md)).

## 5. Agent AI — Implementação Técnica

(Design em [07-AI](07-NPC-AI-ARCHITECTURE.md); aqui, a engenharia.)

### 5.1 Camadas técnicas
- **Tier 0/1 (Mass Entity / ECS):** agentes como entidades de dados; sistemas processam em lote (SIMD-friendly), milhares a custo baixo.
- **Tier 2 (Agentes profundos):** objetos de agente com componentes de Personalidade, Memória (handle para o grafo), Objetivos, Estado. Decisão via **Utility AI + GOAP + Behavior Trees**. Atualizados em frequência reduzida (não todo frame).
- **Tier 3 (Diálogo generativo):** subsistema de conversação (ver §5.3).

### 5.2 Knowledge Graph & Memória (persistência)
- **Grafo social global** + **subgrafos de memória por agente** — armazenados num **banco de grafo embarcado** (in-process, serializável no save) para single-player; espelhável em serviço de grafo gerenciado para a camada online (§6).
- **Operações:** inserção de memórias episódicas (eventos), consultas de recuperação (RAG por relevância/recência/emoção), e **compactação/sumarização periódica** (decaimento de saliência — [07](07-NPC-AI-ARCHITECTURE.md) §3.3) para manter o tamanho do save sob controle.
- **Indexação vetorial** (embeddings) para recuperação semântica de memórias quando a camada LLM está ativa.

### 5.3 Pipeline de Diálogo Generativo (arquitetura híbrida)
Implementa [07-AI](07-NPC-AI-ARCHITECTURE.md) §4:
```
Player input → Intent classifier (modelo pequeno local)
   ├─ mecânico → resolver por sistema + linha curada (0 custo de inferência)
   └─ aberto → Context Builder (RAG: perfil + Big Five + memórias + mood + estado)
                 → Inference Router:
                     1) SLM on-device (latência baixa, custo zero marginal)
                     2) Cloud LLM (qualidade alta; orçamento por sessão)
                     3) Curated fallback (offline / orçamento esgotado)
                 → Output validator (consistência + safety + persona)
                 → Function-call resolver (ações validadas pelo sistema)
```
- **Controle de custo:** orçamento de tokens por sessão; cache de respostas; preferência por on-device; "important moments" priorizam cloud (ver custo em [12-Risk](12-BUSINESS-PLAN.md)).
- **Privacidade & conformidade:** conteúdo gerado passa por filtros de classificação etária; modo "diálogo determinístico" para plataformas/usuários que exigirem.
- **Provedor:** abstração de provedor de LLM (a stack não amarra a um fornecedor); avaliação contínua de modelos por qualidade/custo/latência.

## 6. Backend & Online Architecture

> O **single-player é o produto core e roda offline**. O backend serve a **camada online persistente** (assíncrona/coop — não é um MMO de tempo real).

### 6.1 Topologia de serviços (cloud, microsserviços)
```
            ┌──────────── API Gateway ────────────┐
            │                                       │
 ┌──────────┴─────────┐   ┌────────────┐   ┌───────┴────────┐
 │ Identity / Accounts │   │ Save/Cloud │   │ Player Profile  │
 └─────────────────────┘   │  Sync      │   │ & Progression   │
 ┌─────────────────────┐   └────────────┘   └────────────────┘
 │ Live Ops / Content   │   ┌────────────┐   ┌────────────────┐
 │ (DLC, events, econ   │   │ Social /   │   │ Telemetry /     │
 │  config push)        │   │ Friends /  │   │ Analytics       │
 └─────────────────────┘   │ Graph      │   └────────────────┘
 ┌─────────────────────┐   └────────────┘   ┌────────────────┐
 │ Shared World /       │   ┌────────────┐   │ AI Inference    │
 │ Async Multiplayer    │   │ Commerce / │   │ Gateway (LLM)   │
 │ (sessions/instances) │   │ Store      │   │ + cost control  │
 └─────────────────────┘   └────────────┘   └────────────────┘
```

- **Stack:** serviços containerizados (Kubernetes), event streaming (Kafka/PubSub) para EDA distribuída, APIs REST/gRPC, autoscaling.
- **AI Inference Gateway:** centraliza chamadas de LLM cloud, faz roteamento, caching, rate-limiting e **controle de custo** por usuário/sessão (crítico — [12-Risk](12-BUSINESS-PLAN.md)).
- **Live Ops backbone:** push de configs de economia, eventos sazonais, balanceamento e conteúdo **sem patch de cliente** (essencial para o modelo de serviço — [12](12-BUSINESS-PLAN.md)).

### 6.2 Multiplayer Architecture (a camada online)
> **Decisão de design:** MOGUL **não** é um MMO de mundo compartilhado em tempo real (custo/risco proibitivos e desnecessário para a fantasia). É um **online persistente assíncrono** com coop opcional.

Modos online (faseados — ver [12](12-BUSINESS-PLAN.md)):
- **Shared Economy Worlds (assíncrono):** múltiplos jogadores num mesmo "mundo persistente" onde competem/cooperam na *mesma economia*, mas agem em seus próprios tempos. Suas empresas, marcas e movimentos aparecem no mundo dos outros (rivais reais misturados a rivais-IA).
- **Coop (small group):** amigos como sócios/parceiros num empreendimento compartilhado, ou rivais diretos.
- **Leaderboards & Seasons:** rankings (net worth, influência) e "temporadas" econômicas com leaderboards e recompensas cosméticas.
- **Assíncrono por design:** o estado do jogador é simulado pelo servidor quando offline (ou aproximado), evitando exigência de presença simultânea — respeita a fantasia single-player e reduz custo de infra.
- **Anti-cheat & integridade econômica:** validação server-authoritative das transações em mundos compartilhados; detecção de exploits econômicos.

## 7. Save System & Persistência

> **Desafio:** persistir um mundo *enorme e dinâmico* (economia + milhares de agentes com memória de anos) de forma confiável, performática e à prova de corrupção — em saves que podem durar centenas de horas.

### 7.1 Estratégia de save
- **Modelo de estado em camadas:**
  - **Estado do jogador** (avatar, finanças, ativos, skills) — pequeno, salvo sempre.
  - **Estado das empresas** (do jogador e rivais relevantes) — médio.
  - **Estado de agentes profundos** (perfis + objetivos + **memória/grafo**) — o maior componente; gerido por compactação/saliência ([07](07-NPC-AI-ARCHITECTURE.md) §3.3, §5.2 aqui).
  - **Estado de mundo macro** (economia, mercados, world flags) — médio.
  - **Agentes Tier 0/1 e mundo "dormente"** — **não** persistidos individualmente; **regenerados deterministicamente** a partir de seed + estado macro (economia massiva de espaço).
- **Persistência incremental/delta:** salva deltas, não o mundo inteiro a cada vez (performance e tamanho).
- **Serialização versionada:** schema versionado com migração — **crítico** porque saves precisam sobreviver a patches e DLCs por anos ([12](12-BUSINESS-PLAN.md)).
- **Robustez:** saves atômicos (write-then-swap), checksums, múltiplos slots + autosaves rotativos, e **cloud save** (backend §6) com resolução de conflito.
- **Determinismo regenerativo:** o que pode ser recriado por seed *não* é salvo — a chave para manter saves gerenciáveis num mundo "infinito".

### 7.2 Metas de performance de save
- Autosave sem stutter perceptível (em background/incremental).
- Tamanho de save controlado mesmo após centenas de horas (via compactação de memória + regeneração determinística).
- Load de save longo em tempo aceitável de plataforma AAA.

## 8. Database / Data Architecture

| Domínio | Tecnologia | Razão |
|---------|-----------|-------|
| **Design data (nichos, econ, agentes-template)** | DataAssets / Data Tables (UE5) + pipeline | Data-driven, hot-reload, versionável em Git |
| **Save / world state (cliente)** | Formato binário proprietário versionado | Performance, tamanho, integridade ([§7]) |
| **Grafo social/memória (cliente)** | Graph store embarcado serializável | Consultas de relação/memória eficientes |
| **Backend — contas/progressão/commerce** | SQL relacional gerenciado | Consistência transacional |
| **Backend — grafo social online / mundos** | Graph DB gerenciada | Relações em escala, mundos compartilhados |
| **Backend — telemetria/analytics** | Data warehouse + streaming | Live Ops, balanceamento data-driven, ML |
| **Backend — busca/memória vetorial (LLM)** | Vector DB | RAG de memórias na camada online |

## 9. Content Pipeline

> Produzir e *operar* uma cidade AAA + catálogos enormes (imóveis, veículos, roupas, nichos) exige um pipeline industrializado e **expansível por Live Ops**.

- **Asset pipeline:** DCC tools (Maya/Blender/ZBrush/Houdini) → ingestion → Nanite → validação automatizada → engine. **Houdini + PCG** para conteúdo procedural de cidade em escala ([04-World](04-WORLD-DESIGN.md) §7).
- **MetaHuman pipeline:** geração/variação em escala de população crível; biblioteca de "humanos base" + variação procedural para diversidade ([07](07-NPC-AI-ARCHITECTURE.md)).
- **Data/design pipeline:** nichos, parâmetros econômicos, templates de agentes e eventos como **dados editáveis** por designers (sem engenheiro), validados por testes automatizados.
- **Localização pipeline:** strings externalizadas; suporte a 12 idiomas no lançamento (full VO em 6) — incluindo a complexidade de **conteúdo gerado por LLM** (estratégia: gerar em idioma-base + tradução supervisionada/curada para conteúdo crítico; ver [12](12-BUSINESS-PLAN.md)).
- **CI/CD:** builds automatizados, testes (unit, sim, smoke), build farm, perfis de performance por plataforma. Conteúdo de Live Ops entregue via backend (§6.1) sem patch de cliente quando possível.
- **Telemetria → conteúdo:** dados de jogadores realimentam balanceamento e priorização de conteúdo (loop de Live Ops — [12](12-BUSINESS-PLAN.md)).

## 10. Plataformas, Performance & Escalabilidade

### 10.1 Alvos de plataforma & performance
- **PC (lead platform):** escalável de "min spec" a "ultra"; 60fps alvo em hardware recomendado; settings amplos.
- **PS5 / PS5 Pro / Xbox Series X|S:** modos "Performance" (60fps alvo) e "Fidelity" (30fps, visual máximo). **Series S** como restrição-limite de memória/perf (budget específico).
- **Budget de performance por distrito:** cada distrito tem um orçamento de densidade/draw/sim para garantir framerate (densidade é gerida, não infinita — [04-World](04-WORLD-DESIGN.md)).
- **Cloud streaming & next-gen:** arquitetura pronta para streaming e para a geração seguinte (pós-lançamento).

### 10.2 Scalability Plan (cliente)
- **LOD de geometria (Nanite), de simulação (§3.1) e de cognição ([07] §2)** — três eixos que mantêm um mundo "infinito" dentro de um budget finito.
- **Streaming (World Partition)** + regeneração determinística ([§7]) = mundo grande, memória controlada.
- **Degradação graciosa:** em hardware fraco, reduz densidade de agentes profundos, frequência de sim distante, e desativa LLM cloud — **sem quebrar o jogo** (IA é enhancement — §1).

### 10.3 Scalability Plan (backend / serviço)
- **Stateless services + autoscaling** (K8s) para picos de lançamento e eventos sazonais.
- **AI Inference Gateway** dimensiona e controla custo de LLM elasticamente; fallback para on-device sob pressão de custo/carga.
- **Sharding de mundos compartilhados** e de grafo social online para crescer com a base.
- **Observabilidade:** métricas, tracing distribuído, alertas — operável como um SaaS (a disciplina de Live Ops exige isso — [12](12-BUSINESS-PLAN.md)).

## 11. Segurança, Privacidade & Conformidade
- **Dados de jogador:** conformidade GDPR/LGPD; minimização; criptografia em trânsito e repouso.
- **Conteúdo de IA:** guard-rails de segurança, filtros etários, e transparência (rotular a presença de IA generativa); opção de opt-out (modo determinístico — §5.3).
- **Integridade econômica online:** server-authoritative, anti-cheat, detecção de exploit (§6.2).
- **Comércio:** PCI-compliant via provedores; monetização não-predatória por design ([12](12-BUSINESS-PLAN.md)).

---

> **Anterior:** [← 09 — UX/UI](09-UX-UI.md) · **Próximo:** [11 — Production Plan →](11-PRODUCTION-PLAN.md)

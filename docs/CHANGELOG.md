# Changelog — Bíblia de Pré-Produção (Project ATLAS / MOGUL)

Registro de versões da documentação de pré-produção. Segue versionamento semântico de documento (Major.Minor).

## [1.0.0] — 2026-06-23 — *Concept Complete / Pré-Produção*
### Adicionado
- **Estrutura completa da bíblia** (13 documentos + glossário + changelog).
- **README** master com índice, fatos canônicos (single source of truth), pilares e guia de leitura por stakeholder.
- **00 — Executive Summary:** pitch, problema de mercado, USP, 5 fases, números-chave, projeções e riscos (resumo).
- **01 — Product Vision & Core Pillars:** visão fundamental, 7 emoções-alvo, 5 fases emocionais detalhadas, 3 pilares, Pillar Gate (princípio mestre), tom, bússola de design.
- **02 — Market, Audience & Competition:** personas, motivações (Bartle), TAM/SAM/SOM, mapa competitivo, SWOT, USP/trifecta, posicionamento.
- **03 — Gameplay Design:** 5 loops aninhados, 5 fases (gating de mecânicas), progressão de personagem, estilos de vitória, endgame, New Game+ geracional, economia da atenção.
- **04 — World Design:** Meridian City, 6 distritos + aeroporto, verticalidade/camadas sociais, cidade viva, eventos, escala/pipeline, expansibilidade.
- **05 — Economy & Financial Systems:** arquitetura em 4 camadas, macroeconomia viva, mercados setoriais, agentes econômicos, finanças corporativas e pessoais, mercado de capitais, alavancas de influência, crime econômico, balanceamento.
- **06 — Business & Corporate Growth:** ciclo de vida da empresa, setores/nichos + template de mecânica, operações, funcionários como agentes, liderança/cultura, M&A completo, sinergias/conglomerados, concorrência por IA, marca.
- **07 — NPC & Agent AI Architecture:** tese de agentes, LOD de cognição (Tier 0–3), anatomia do agente (perfil/Big Five/memória/comportamento), knowledge graph, diálogo híbrido + guard-rails, networking, grafo social, reputação multidimensional, emergência.
- **08 — Real Estate, Offices & Vehicles:** ativos como linguagem de status, imóveis (4 papéis), escritórios físicos como narrativa visual, veículos como sinal social, Status como sistema unificado.
- **09 — UX/UI Design:** interface diegética em 3 camadas, MeridianOS, consultores-IA, UX flows principais, HUD, legibilidade causal, acessibilidade AAA, direção de arte de UI.
- **10 — Technical Architecture:** stack UE5.6, Simulation Core + LOD de simulação, EDA, Economy Engine, Agent AI técnico, diálogo híbrido, backend/online/multiplayer assíncrono, save system, database, content pipeline, escalabilidade, segurança/conformidade.
- **11 — Production Plan:** roadmap ~6 anos/6 fases, gates, definição de Vertical Slice e MVP, full production, estrutura de equipe (strike teams), budget (~USD 195M) por ano e categoria, riscos de produção.
- **12 — Business Plan & Live Ops:** revenue model em camadas, projeções (3 cenários), break-even/ROI, unit economics de IA, GTM/marketing, matriz de riscos completa (15 riscos), post-launch/Live Ops, DLC/expansões, KPIs, visão de 5 anos.
- **Glossário** e **Changelog**.

### Decisões canônicas estabelecidas nesta versão
- Título **MOGUL**; codinome **Project ATLAS**; cidade **Meridian City** (6 distritos + MER).
- Engine **UE5.6**; plataformas PC (lead) + PS5/Series; modelo **premium + serviço não-predatório**.
- Modelo de IA **híbrido** (on-device + cloud + fallback determinístico); IA como *enhancement*, não dependência crítica.
- Multiplayer **assíncrono persistente** (não MMO de tempo real).
- Orçamento de produção **~USD 195M**; marketing **~USD 90M**; lançamento-alvo **T4 2032**.

---

### Como evoluir este documento
- Mudanças nos **fatos canônicos** começam no [README](../README.md) e propagam.
- Cada alteração relevante incrementa a versão e registra aqui (data, seções afetadas, racional).
- Versões: **Major** = mudança de visão/pilar/escopo; **Minor** = detalhamento/ajuste dentro da visão.

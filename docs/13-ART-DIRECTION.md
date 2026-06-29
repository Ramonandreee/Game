# 13 — Art Direction & Visual Identity (AAA / Fotorrealista)

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 13 de 13 · Confidencial
> *Inclui: Identidade Visual, Design System (UI), Direção de Arte 3D Fotorrealista, Performance*

---

## 1. Filosofia Visual

> **MOGUL não pode parecer software interno, painel administrativo, protótipo ou jogo indie. Tem de parecer feito por um grande estúdio.**

A identidade visual transmite, em cada tela e cada rua: **sucesso, crescimento, riqueza, poder empresarial, luxo discreto, tecnologia, eficiência, inovação.** O jogador deve *sentir* que constrói um império.

Bússola estética (em ordem de prioridade):
1. **Fidelidade física** (PBR, luz baseada em física) no mundo 3D.
2. **Luxo discreto** — premium sem espalhafato; cor usada com parcimônia.
3. **Consistência absoluta** — uma única linguagem (cantos, sombras, tipografia, espaçamento, animação).
4. **Minimalismo** — muito espaço negativo; informação aparece quando necessária.
5. **Polimento** — micro-animações, alinhamento perfeito, nada arbitrário.

> **Referência = nível de qualidade e acabamento das maiores produções contemporâneas.** Nada de copiar elementos característicos de franquias específicas. Toda identidade, arquitetura e direção de arte são **originais**.

## 2. Honestidade de Escopo (o que é alcançável onde)

| Camada | Onde vive | Teto de qualidade realista |
|--------|-----------|-----------------------------|
| **UI / HUD / menus** | Protótipos `game/` e `world/` (HTML/CSS) | **AAA de verdade já agora** — design system premium completo (§3) |
| **Mundo 3D no protótipo** | `world/` (Three.js/WebGL) | Estilizado-realista; tone mapping, bloom, env reflections, fog, materiais PBR-ish. **Não** é fotorrealismo |
| **Fotorrealismo pleno** | Produção **UE5.6** (`ue5/`) — ver [doc 10](10-TECHNICAL-ARCHITECTURE.md), [doc 11](11-PRODUCTION-PLAN.md) | MetaHuman, Nanite, Lumen/GI, vegetação por folha, materiais PBR completos |

> Fotorrealismo "indistinguível de uma foto" é a **produção em engine** (Lumen GI, ray tracing, MetaHumans, Nanite, vegetação procedural). Este documento define a **direção** que essa produção persegue, e o **design system** que já elevamos na UI dos protótipos.

## 3. Design System (UI) — a linguagem única

Aplicado de forma idêntica em `game/` e no HUD de `world/`. Tudo deriva de **design tokens**; nada tem medida arbitrária.

### 3.1 Grid & espaçamento
- **Base 8px.** Escala: 4 · 8 · 12 · 16 · 24 · 32 · 48 · 64.
- Respiros generosos; densidade controlada; nada apertado, nada esparso.

### 3.2 Raios (cantos)
`--r-sm:8px · --r-md:12px · --r-lg:16px · --r-xl:22px` · chips/pills 999px. Um raio por função, sempre o mesmo.

### 3.3 Elevação (sombras) & profundidade
Três níveis: `--e-1` (sutil), `--e-2` (cards/topbar), `--e-3` (modais). Superfícies em **vidro** (blur + saturação) com **hairlines** (rgba branco .05–.13) e realce superior. Vinheta sutil de fundo para profundidade.

### 3.4 Cor (paleta refinada, pouca cor)
- **Base:** near-black levemente azulado (`#070a0e` → `#0e131a`), em camadas de superfície translúcida.
- **Acento único:** **ouro discreto** (`#e7cb86` / `#c9a24e`) — usado só para destacar o que importa (valores, foco, marca).
- **Funcionais (econômicas):** verde (`#48d49a`), vermelho (`#f0726a`), azul (`#6aa8f0`).
- **Texto:** alto contraste off-white (`#eef2f7`), muted, dim. **Muito branco negativo, muito espaço.**

### 3.5 Tipografia
- Stack premium (Inter/SF Pro/system). Hierarquia clara: **display** (hero, tracking largo), **título**, **subtítulo**, **corpo**, **legenda**, **valor**.
- **Números sempre `tabular-nums`** (alinhamento de valores monetários).
- Poucos tamanhos; peso e tracking fazem a hierarquia, não dezenas de tamanhos.

### 3.6 Movimento
- Tokens: `--ease:cubic-bezier(.22,.61,.36,1)`, durações `--fast .14s` / `--med .22s`.
- **Nada instantâneo:** hover (lift sutil), fade, scale, slide. Modais entram com scale+fade. Focus com anel dourado acessível.

### 3.7 Componentes (todos conversam entre si)
Topbar (glass) · Cards (glass + realce) · Tabs (segmented control) · Botões (primary/gold, secondary, ghost, small; estados hover/active/focus/disabled) · Inputs · Modais · Rows/listas · KPIs · Tags/pills · Barras · Toast (glass) · Radar/HUD · Prompt contextual. **Um só vocabulário visual.**

## 4. Direção de Arte 3D (alvo fotorrealista — produção UE5)

### 4.1 Materiais (PBR completo)
Todo material: **Albedo · Normal · Roughness · Metallic · AO · (Height quando necessário).**
- **Vidro:** espessura, refração, reflexão, transparência física.
- **Metal:** resposta correta à luz + reflexos.
- **Madeira:** fibras naturais. **Concreto:** desgaste. **Asfalto:** rachaduras, remendos, variação. **Mármore/cerâmica/plástico/água:** cada um com assinatura física.

### 4.2 Iluminação (baseada em física)
GI (Lumen) · sombras em cascata + suaves · luz indireta/bounce · reflexos em tempo real (Lumen/SSR) · AO · volumetria (god rays, neblina) · céu físico · **exposição automática / adaptação dos olhos** · Golden Hour, noite convincente, neon e luzes urbanas.

### 4.3 Personagens (padrão captura facial/corporal)
Anatomia correta, biotipos/idades/etnias variados, pele com poros e microdetalhe, rugas, barba/cabelo por fios, sobrancelhas/cílios, olhos fisicamente corretos, dentes, unhas, imperfeições. Roupas com materiais distintos (algodão, couro, jeans, lã, seda, sintéticos) reagindo à luz. **Pipeline: MetaHuman** ([doc 07](07-NPC-AI-ARCHITECTURE.md), [doc 10](10-TECHNICAL-ARCHITECTURE.md)).

### 4.4 Animação (sem sensação robótica)
Aceleração/desaceleração natural, peso e transferência de massa, movimento secundário, correções de equilíbrio, respiração, micromovimentos involuntários, piscadas, olhar dinâmico, faciais sutis.

### 4.5 Veículos
Interior modelado, painel, bancos com costuras, cintos, volante, espelhos, suspensão funcional, pneus/freios/discos/pinças, pintura multicamadas, reflexos, sujeira dinâmica e desgaste progressivo. Cada categoria com identidade própria; nada genérico.

### 4.6 Cidade (metrópole viva)
Fachadas únicas (sem repetição perceptível), vitrines e interiores visíveis com luz interna, letreiros/placas, semáforos, postes, cabos, lixeiras, bancos, hidrantes, caixas elétricas, bueiros, calçadas detalhadas, ciclovias, sinalização horizontal, vegetação urbana. Cada região conta uma história: financeiro, comercial, residencial, industrial, portuário, rural — coerentes com [doc 04](04-WORLD-DESIGN.md).

### 4.7 Vegetação
Árvores completas (galhos, folhas individuais, variação), arbustos, flores, capim; vento, sombras próprias, subsurface (luz atravessando folhas); compatível com o bioma da região.

### 4.8 Atmosfera & vida
Pássaros, insetos, fumaça distante, poeira, folhas ao vento, vapor de bueiros, poças e reflexos pós-chuva, marcas de pneu, lixo ocasional, pedestres e trânsito coerentes. **Cada rua transmite atividade constante.**

### 4.9 Céu & clima
Nuvens volumétricas, nascer/pôr do sol, lua, estrelas, mudança de luz ao longo do dia; sistema de clima (sol, chuva, garoa, tempestade, neblina, vento), cada um alterando a atmosfera.

### 4.10 Efeitos (sem exagero)
Bloom discreto, motion blur configurável, DOF, SSR, partículas (dust/smoke/rain), heat haze, lens dirt e lens flare discretos.

## 5. Mundo como UI (diegese) & Multiplayer-ready
- HUD minimalista; informação contextual; menus inteligentes; transições cinematográficas (alinha com [doc 09](09-UX-UI.md)).
- Design **preparado para multiplayer**: nomes de jogadores, indicadores, listas eficientes, chat, convites, guildas, empresas, mercado — componentizados e escaláveis desde já ([doc 10](10-TECHNICAL-ARCHITECTURE.md) §6).

## 6. Responsividade
Funciona sem quebra em UltraWide, 4K, 2K, 1080p, 1366×768, Windows com escala, Linux e (futuro) Steam Deck. Tokens + grid garantem proporção em qualquer resolução.

## 7. Performance (visual AAA sem desperdício)
LOD, instancing, occlusion culling, streaming (World Partition), texture streaming + mipmaps, meshes otimizadas, **Nanite** quando aplicável, **Virtual Textures**, bom uso de memória. Cada ganho visual respeita o budget por distrito ([doc 10](10-TECHNICAL-ARCHITECTURE.md) §10).

## 8. Organização (tema reutilizável)
Tema global + design tokens + componentes reutilizáveis; zero duplicação; nada de medidas mágicas. A UI dos protótipos já segue isto; a produção UE5 espelha os mesmos tokens em UMG/Slate.

---

> **Anterior:** [← 12 — Business Plan](12-BUSINESS-PLAN.md) · **Voltar ao índice:** [README](../README.md)

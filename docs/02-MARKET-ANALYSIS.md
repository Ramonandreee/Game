# 02 — Market, Audience & Competition

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 02 de 12 · Confidencial

---

## 1. Tese de Mercado

> **Existe uma demanda massiva e comprovada por (a) simulação de vida e (b) fantasia de empreendedorismo/poder, mas nenhum produto AAA jamais uniu as duas com imersão de mundo aberto. MOGUL ocupa um espaço em branco de alto valor entre *The Sims* e a Paradox.**

A oportunidade nasce de uma convergência cultural e tecnológica:

- **Cultural:** a "hustle culture", o boom de conteúdo de finanças/empreendedorismo (FinTok, business YouTube), e o fascínio cultural por fundadores e magnatas estão em máxima histórica. A fantasia de "construir um império" é um dos desejos aspiracionais mais difundidos da década.
- **Tecnológica:** UE5 (densidade urbana acessível), MetaHuman (população crível barata) e IA agêntica (NPCs com mente) maturaram ao ponto de viabilizar o produto que a barreira técnica antes proibia.

## 2. Público-Alvo

### 2.1 Personas primárias

#### Persona A — "O Estrategista Aspiracional" (núcleo)
- **Idade:** 25–40. Predomínio masculino, mas com cauda feminina relevante e crescente.
- **Perfil:** joga sims de gestão/estratégia (Cities: Skylines, Civilization, Paradox), gosta de profundidade e otimização. Frequentemente trabalha em tech, finanças, ou é empreendedor/aspirante.
- **Motivação (Bartle/derivado):** *Achiever + Explorer de sistemas*. Quer dominar sistemas complexos e ver progresso mensurável.
- **O que o conquista:** profundidade econômica real, M&A, otimização de conglomerado.
- **Risco de churn:** se for raso demais ("Sims com dinheiro").

#### Persona B — "O Imersivo Narrativo" (núcleo)
- **Idade:** 22–38, distribuição de gênero equilibrada.
- **Perfil:** joga RPGs de mundo aberto (GTA, Cyberpunk, RDR2, BG3). Valoriza personagem, mundo, história, role-play.
- **Motivação:** *Immersion + Socializer*. Quer *viver um papel* e formar laços com personagens.
- **O que o conquista:** NPCs com mente, networking, consequências, "minha história".
- **Risco de churn:** se for abstrato/planilhento demais.

#### Persona C — "O Fantasista de Poder" (expansão de massa)
- **Idade:** 18–35, amplo.
- **Perfil:** consome conteúdo de "ficar rico", joga mobile tycoons, fã de *The Sims*. Menos hardcore, mais movido por fantasia e expressão.
- **Motivação:** *Power fantasy + Self-expression*. Quer sentir ascensão, status, customização (carros, mansões, roupas).
- **O que o conquista:** progressão visível, status, customização, momentos "screenshot".
- **Risco de churn:** se a curva inicial (sobrevivência) for punitiva/lenta demais.

### 2.2 Persona secundária — "O Criador de Conteúdo"
Streamers e criadores de YouTube/TikTok são um **canal de marketing e um segmento de design**. MOGUL é projetado para gerar histórias emergentes ("clipáveis"): a aquisição hostil que deu errado, o funcionário que virou rival, a falência dramática. Ferramentas de captura/replay e legibilidade de eventos são requisitos de design (ver [09-UX-UI](09-UX-UI.md)).

### 2.3 Matriz Bartle / motivações atendidas
| Tipo | Como MOGUL atende |
|------|-------------------|
| **Achiever** | Conglomerados, net worth, rankings, conquistas visíveis, dominação de mercado |
| **Explorer** | Mundo aberto denso, descoberta de NPCs/oportunidades, profundidade de sistemas econômicos |
| **Socializer** | Networking, agentes com memória, sócios, online layer, relações de longo prazo |
| **Killer** | Aquisições hostis, sabotagem competitiva, manipulação de mercado, PvP econômico (online) |

## 3. Dimensionamento de Mercado (TAM / SAM / SOM)

> *Estimativas de pré-produção, a serem refinadas com pesquisa primária na Fase de Concept. Ordens de grandeza, não previsões.*

| Camada | Definição | Estimativa |
|--------|-----------|-----------|
| **TAM** | Jogadores de PC+console no mundo dispostos a comprar AAA premium | ~700–900M jogadores; mercado AAA premium ~USD 60–75B/ano |
| **SAM** | Fãs de simulation + management + open-world RPG (sobreposição de gêneros) | ~120–180M jogadores |
| **SOM (5 anos)** | Fatia realista capturável dado marketing AAA e categoria nova | ~8–15M de compradores acumulados |

### Sinais de validação de demanda
- **The Sims:** franquia com 200M+ de unidades históricas → apetite de massa por life sim.
- **GTA V:** 200M+ de cópias → apetite por mundo aberto urbano de alta densidade e fantasia adulta.
- **Cities: Skylines / Paradox:** comunidades de gestão profundas e leais (DLCs como modelo de receita recorrente).
- **Game Dev Tycoon / Software Inc. / Capitalism Lab:** provam o nicho "business sim", limitado por produção indie.
- **Sinais culturais:** crescimento explosivo de conteúdo de finanças pessoais e empreendedorismo entre 2020–2026.

## 4. Análise da Concorrência

### 4.1 Mapa competitivo (eixos: Imersão/Mundo × Profundidade de Negócios)

```
            ALTA PROFUNDIDADE DE NEGÓCIOS
                        ^
   Capitalism Lab •     |      ★ MOGUL (espaço-alvo)
   Paradox (EU/Vic) •   |
   Software Inc. •      |
   The Founder •        |
 -----------------------+--------------------------> ALTA IMERSÃO / MUNDO ABERTO
   Game Dev Tycoon •    |        • GTA / Cyberpunk (vida, não negócio)
   Mobile tycoons •     |        • The Sims (vida, raso em negócio)
                        |        • BitLife (texto, raso)
            BAIXA PROFUNDIDADE DE NEGÓCIOS
```

O quadrante superior-direito (**alta profundidade de negócios + alta imersão de mundo aberto**) está **vazio**. É o território de MOGUL.

### 4.2 Concorrentes diretos e adjacentes

| Concorrente | Força | Fraqueza (nossa abertura) |
|-------------|-------|---------------------------|
| **The Sims 4 / "Project Rene"** | Life sim de massa, customização, marca | Raso em economia/negócios; tom infantilizado; sem fantasia de poder adulta |
| **Capitalism Lab** | Profundidade econômica extrema | UI de planilha, sem imersão, nicho, datado |
| **Paradox (Victoria 3, etc.)** | Simulação macro profunda, modelo de DLC | Abstrato/top-down; não é "uma vida"; curva de entrada brutal |
| **Software Inc. / Startup Company** | Simulação de empresa charmosa | Indie, escopo limitado, sem mundo/NPCs vivos |
| **GTA / Cyberpunk 2077** | Mundo aberto AAA, imersão | Negócio é raso/inexistente; foco em crime/ação |
| **BitLife** | Life sim acessível, viral | Texto puro, sem imersão, raso |
| **Mobile tycoons / idle** | Monetização, alcance | Predatórios, rasos, sem fantasia de "ser uma pessoa" |

### 4.3 Análise SWOT (MOGUL)

**Strengths**
- Categoria nova sem incumbente AAA (vantagem de pioneirismo).
- Moat tecnológico (agentes + economia autônoma) difícil de replicar.
- Fantasia universal e aspiracional com forte sinergia com criadores de conteúdo.

**Weaknesses**
- Escopo e custo enormes; risco de execução alto.
- Risco de "fun-finding": simulação econômica pode ser complexa sem ser divertida.
- Dependência de tecnologia de IA ainda em amadurecimento (custo/latência).

**Opportunities**
- Definir e ser dono de uma categoria inteira (como *The Sims* é dono do life sim).
- Modelo de Live Ops + expansões de altíssimo LTV (mercados, cidades, setores).
- Creator/UGC economy de longo prazo.

**Threats**
- Um incumbente (EA/Paradox/Rockstar) entra no espaço com IP estabelecido.
- Backlash contra IA generativa (custo de percepção; ver [12-Risk](12-BUSINESS-PLAN.md#risk-analysis)).
- Macro de mercado de games (janelas de lançamento lotadas, fadiga de AAA).

## 5. Unique Selling Proposition (USP)

> **A única simulação de vida onde cada número tem um corpo no mundo, e cada pessoa tem uma mente.**

### Os três diferenciais combinados (o "trifecta" inimitável)

1. **Diegese radical** — nenhum concorrente entrega negócios profundos *sem menus*, vividos em primeira/terceira pessoa.
2. **NPCs agênticos persistentes** — nenhum concorrente tem uma sociedade de agentes com memória de anos, personalidade e objetivos próprios em escala.
3. **Economia autônoma viva** — nenhum concorrente tem um ecossistema de empresas-IA + macroeconomia que prospera/quebra sem o jogador.

Qualquer concorrente pode copiar **um** desses. O **moat** está na **integração dos três** numa produção AAA coesa — anos de vantagem e um ciclo de dados que melhora o conteúdo emergente com o tempo.

## 6. Estratégia de Posicionamento

- **One-liner de marketing:** *"Live the empire."* / *"De um quarto apertado a um império global."*
- **Categoria reivindicada:** "The AAA Life-Business Sim."
- **Âncora de comparação para o público:** *"É o GTA dos negócios"* / *"The Sims para quem quer poder de verdade."*
- **Prova social-alvo:** queremos que a comunidade compartilhe histórias emergentes ("MOGUL stories") como prova viva do diferencial.

## 7. Riscos de mercado e mitigação (resumo)
| Risco de mercado | Mitigação |
|------------------|-----------|
| Educar o mercado sobre uma categoria nova é caro | Âncoras de comparação claras; marketing focado em fantasia, não em sistemas |
| Janela de lançamento competitiva | Vantagem de pioneirismo; flexibilidade de data; beta/early-access para fidelizar cedo |
| Percepção negativa sobre IA generativa | Comunicar IA como "NPCs com mente", não como gimmick; garantir guard-rails e qualidade (ver [07-AI](07-NPC-AI-ARCHITECTURE.md)) |

Matriz de risco completa: [12-Business-Plan](12-BUSINESS-PLAN.md#risk-analysis).

---

> **Anterior:** [← 01 — Product Vision](01-PRODUCT-VISION.md) · **Próximo:** [03 — Gameplay & Meta Loops →](03-GAMEPLAY-DESIGN.md)

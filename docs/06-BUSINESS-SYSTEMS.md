# 06 — Business & Corporate Growth Systems

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 06 de 12 · Confidencial

---

## 1. Visão Geral

Este é o sistema-coração de MOGUL: como o jogador **funda, opera, compra, vende, funde e encerra** empresas, contrata e lidera **pessoas**, e transforma tudo isso num **império**. Tudo aqui obedece ao Pilar I (diegese) — operações são *vividas*, não gerenciadas por planilha (ver [01-Vision](01-PRODUCT-VISION.md)).

## 2. O Ciclo de Vida da Empresa

```
   FUNDAR ──► OPERAR ──► CRESCER ──► (ESCOLHA) ──► ESCALAR (holding)
     │           │          │              │            │
     │           │          │              ├──► VENDER (exit)
     │           │          │              ├──► FUNDIR (M&A)
     │           ▼          ▼              ├──► ABRIR CAPITAL (IPO)
     └──► (risco de FALÊNCIA / ENCERRAR) ◄─┘
```

### Operações disponíveis com empresas
| Operação | Descrição | Fase típica |
|----------|-----------|-------------|
| **Abrir** | Fundar do zero: nicho, nome, marca, capital, local | 1–2 |
| **Comprar** | Adquirir empresa existente (amigável ou hostil) | 3+ |
| **Vender** | Exit total ou parcial (a um rival-IA, PE, ou via IPO) | 3+ |
| **Fundir** | Combinar duas empresas (suas ou com terceiros) buscando sinergia | 3+ |
| **Encerrar** | Fechar/liquidar (estratégico ou por fracasso) | qualquer |

## 3. Segmentos & Nichos de Negócio

> **Meta de design:** centenas de nichos jogáveis, cada um com *mecânicas próprias* — não reskins. Um SaaS não se joga como uma construtora.

### 3.1 Setores-macro (no lançamento)
Cada setor é uma "família" com múltiplos nichos. Lista do core game (expansível via DLC — ver [12](12-BUSINESS-PLAN.md)):

| Setor | Exemplos de nichos | Mecânica distintiva |
|-------|--------------------|--------------------|
| **SaaS / Software** | CRM, ferramentas B2B, apps | MRR/churn, escalabilidade quase infinita, baixo custo marginal |
| **IA / Deep Tech** | Modelos, automação, robótica | P&D pesado, alto risco, hype-driven, talento escasso e caríssimo |
| **Fintech** | Pagamentos, banking, crédito | Regulação pesada, confiança, efeito de rede, risco sistêmico |
| **Construção Civil** | Residencial, comercial, infra | Projetos longos, capital intensivo, ciclos, ligado a imobiliário ([08](08-ASSETS-SYSTEMS.md)) |
| **Energia** | Geração, distribuição, renováveis | Capex enorme, concessões, regulação, horizonte longo |
| **Educação** | Escolas, edtech, cursos | Marca/reputação, escala, ciclos sazonais |
| **Saúde** | Clínicas, healthtech, farma | Regulação, confiança, margens, ético-sensível |
| **Logística** | Entregas, frota, armazéns | Rede física, otimização de rotas, ligada a [04-World](04-WORLD-DESIGN.md) Ironside |
| **Varejo** | Lojas, e-commerce, marcas | Localização, estoque, margem fina, volume |
| **Agronegócio** | Produção, trading de commodities | Ciclos de safra, clima, commodities, exportação |
| **Mídia & Entretenimento** | Estúdios, streaming, eventos | Hits & misses, IP, influência cultural (sinergia com reputação) |
| **Hospitality & Luxo** | Hotéis, restaurantes, clubes | Status, localização (Goldhaven), experiência, sinergia com networking |
| **Indústria / Manufatura** | Fábricas, bens de consumo | Cadeia de suprimentos, capex, escala |
| **Imobiliário** | Incorporação, locação, REITs | Cruza com [08-Assets](08-ASSETS-SYSTEMS.md); ativos físicos no mapa |

### 3.2 Anatomia de um nicho (template de mecânica)
Cada nicho é definido por um conjunto de parâmetros que produzem gameplay distinto:

- **Estrutura de custo:** capex inicial, custo fixo, custo marginal (SaaS ≈ 0; manufatura alto).
- **Curva de margem:** alta/baixa, e como evolui com escala e maturidade do setor.
- **Drivers de demanda:** o que faz clientes comprarem (preço, qualidade, marca, rede, status, necessidade).
- **Fatores-chave de sucesso:** o que o jogador precisa dominar (talento? localização? P&D? marketing? regulação?).
- **Perfil de risco:** volatilidade, exposição a ciclo, risco regulatório/tecnológico.
- **Velocidade:** ciclos rápidos (varejo, software) vs. lentos (energia, construção).
- **Talento requerido:** que tipos de funcionários e quão escassos/caros.
- **Sinergias:** com quais outros nichos combina (ver §7).

> Isso permite gerar **centenas de nichos** combinando parâmetros, mantendo cada um mecanicamente distinto, e adicionar novos via data (ver [10-Tech](10-TECHNICAL-ARCHITECTURE.md), data-driven).

## 4. Operar uma Empresa (o gameplay do dia a dia)

As alavancas que o jogador controla (pessoalmente ou via gerentes-IA):

- **Produto/Serviço:** o que vende, qualidade, P&D, inovação, portfólio.
- **Preço:** posicionamento (premium vs. volume) — tensiona margem × participação de mercado.
- **Pessoas:** contratar, organizar, liderar, reter (ver §5).
- **Marketing & Marca:** awareness, posicionamento, reputação de marca (alimenta demanda — ver [05-Economy](05-ECONOMY-DESIGN.md) §5.1).
- **Operações:** capacidade, eficiência, qualidade, cadeia de suprimentos (por setor).
- **Finanças:** capital, dívida, fluxo de caixa, reinvestimento vs. distribuição (ver [05](05-ECONOMY-DESIGN.md) §6).
- **Estratégia:** posicionamento competitivo, expansão, timing de ciclo.

**Pontos de alavancagem:** o jogador não microgerencia tudo — intervém em **decisões de alto impacto** (contratação-chave, preço, crise, expansão), delegando o resto a gerentes-IA conforme escala ([03-Gameplay](03-GAMEPLAY-DESIGN.md) §8).

## 5. Funcionários — Pessoas, Não Recursos

> **Cada funcionário é um agente único** (ver [07-AI](07-NPC-AI-ARCHITECTURE.md)). Eles têm vida, ambição e memória. Esta é uma das maiores fontes de história emergente do jogo.

### 5.1 Atributos de um funcionário
| Atributo | Significado |
|----------|-------------|
| **Competência** | Skill na função; afeta produtividade e qualidade |
| **Potencial / Carreira** | Quanto pode crescer; trajetória de carreira |
| **Ambição** | Quão faminto por crescimento/poder/dinheiro |
| **Personalidade (Big Five)** | Define comportamento, fit cultural, reações ([07](07-NPC-AI-ARCHITECTURE.md)) |
| **Relacionamentos** | Com você, colegas, rivais; redes internas, panelinhas |
| **Felicidade / Engajamento** | Satisfação; abaixo de um limiar → problemas |
| **Produtividade** | Output real = f(competência, felicidade, liderança, fit, carga) |
| **Lealdade** | Resistência a ser roubado/sair |

### 5.2 O que funcionários fazem (autonomia)
Funcionários **agem por conta própria**, gerando consequências:
- **Pedir aumento / promoção** (e ficar ressentidos se negado injustamente).
- **Pedir demissão** (se infelizes ou cortejados por rivais).
- **Criar concorrentes** — um funcionário talentoso e ambicioso pode sair e **fundar uma empresa rival**, levando conhecimento e clientes (e até outros funcionários).
- **Roubar talentos** — seus líderes podem ser caçados por rivais (e vice-versa: você pode caçar talentos alheios).
- **Virar sócios** — funcionários-chave podem ser promovidos a sócios/parceiros, alinhando interesses (ou criando disputas de poder).
- **Formar cultura/política interna** — alianças, conflitos, fofoca, moral coletivo.

### 5.3 Liderança & Cultura (sistemas)
- **Cultura da empresa** emerge das contratações, da sua liderança e das políticas; afeta produtividade, retenção e atração de talento.
- **Estrutura organizacional (org chart):** conforme escala, você monta hierarquias, define gerentes-IA, e delega — o **org chart é uma ferramenta de gameplay**, não cosmético.
- **Gerentes-IA:** funcionários promovidos a gestão tocam operações sozinhos; sua **competência e lealdade** determinam quão bem (e honestamente) gerem na sua ausência. Um gerente ruim/desonesto pode afundar uma divisão — escolher quem promover é decisão crítica do endgame.

## 6. Fusões & Aquisições (M&A)

O coração da Fase 3+ ([03-Gameplay](03-GAMEPLAY-DESIGN.md)). M&A é vivido como uma **campanha**, não um botão.

### 6.1 Fluxo de uma aquisição
```
Identificar alvo → Due diligence (descobrir o valor/risco real) →
Avaliar (valuation, ver [05] §6.2) → Estruturar oferta (cash/ações/dívida) →
Negociar (com o dono-IA: amigável) OU Hostil (comprar ações no mercado) →
Financiar → Fechar → INTEGRAR (o passo mais difícil)
```

### 6.2 Aquisição amigável vs. hostil
- **Amigável:** negociar com o(s) dono(s)-IA. Depende de **relação, reputação e preço**. Networking abre portas e reduz preço.
- **Hostil:** acumular participação no mercado de capitais (empresa pública) contra a vontade da gestão. Cara, arriscada, gera **inimigos** e atenção da mídia — mas é a fantasia "shark" definitiva.

### 6.3 Due Diligence (descobrir a verdade)
O valor anunciado de um alvo pode esconder problemas (dívidas ocultas, talento desmotivado, clientes saindo). **Due diligence** — via analistas-IA, networking, ou investigação — revela o estado real e o risco. Comprar sem due diligence é roleta-russa (e o jogo te pune por isso).

### 6.4 Integração pós-fusão (onde impérios morrem)
Comprar é fácil; **integrar é difícil** — e é onde está o gameplay profundo:
- **Choque de cultura** entre as equipes (Big Five agregado), fuga de talentos do alvo.
- **Sinergias** prometidas que precisam ser *realizadas* (não são automáticas).
- **Sobreposições** a resolver (demitir? manter? — com custo humano e reputacional).
- Aquisições mal integradas **destroem valor** — um realismo que cria tensão e profundidade.

## 7. Sinergias & Conglomerados (a malha do império)

> Um império é mais que a soma das empresas. **Sinergias** transformam um portfólio em uma máquina.

- **Sinergias verticais:** controlar a cadeia (sua logística serve seu varejo; sua energia abastece sua indústria).
- **Sinergias horizontais:** compartilhar marca, clientes, talento, tecnologia entre empresas do mesmo nível.
- **Sinergias de capital:** usar o caixa de uma vaca leiteira para financiar uma aposta de alto crescimento.
- **Sinergias de dados/influência:** sua mídia promove suas marcas; sua reputação abre portas para todas.
- **Cross-selling:** clientes de uma empresa viram clientes de outra.

Conglomerados também trazem **risco**: complexidade, contágio (uma empresa quebrando contamina o grupo), e atenção regulatória/antitruste no endgame.

## 8. Concorrência por IA (o mundo dos negócios autônomo)

> **As empresas-IA não esperam o jogador.** Elas vivem o mesmo jogo que você. (Detalhe de IA em [07](07-NPC-AI-ARCHITECTURE.md); economia em [05](05-ECONOMY-DESIGN.md).)

Empresas controladas por IA, com seus próprios donos-NPC (agentes), **autonomamente**:
- **Fundam** novos negócios em setores promissores.
- **Contratam e demitem** (competindo por talento com você — incl. seus funcionários).
- **Investem, lançam produtos, mudam preços** (pressionando suas margens).
- **Crescem, estagnam, ou falem** segundo seu desempenho.
- **Compram outras empresas** — incluindo tentar comprar *você* ou seus alvos.
- **Reagem ao jogador:** revidam guerras de preço, contra-atacam aquisições, formam alianças contra um player dominante.

Isso cria um **ecossistema competitivo vivo**: rivalidades emergentes, "vilões" que surgem organicamente, e a sensação de um mundo de negócios que existe por si.

## 9. Marca, Reputação Corporativa & Mídia
- Cada empresa tem **reputação de marca** (≠ sua reputação pessoal — ver [07-Reputação](07-NPC-AI-ARCHITECTURE.md)): qualidade percebida, confiança, prestígio.
- **Mídia-IA** cobre o mundo dos negócios: reporta seus sucessos, fracassos, aquisições e escândalos — moldando percepção pública e valuations ([05](05-ECONOMY-DESIGN.md) §8).
- **Crises de marca** (recall, escândalo, falha pública) são eventos que exigem gestão (RP, recall, pedido de desculpas, ou negação — com consequências).

## 10. Como tudo se conecta (mapa de dependências)
- **Empresas** consomem **talento** ([§5]) e **capital** ([05](05-ECONOMY-DESIGN.md)), competem por **consumidores-IA** ([05](05-ECONOMY-DESIGN.md) §5), e existem em **espaço físico** ([04-World](04-WORLD-DESIGN.md), [08-Assets](08-ASSETS-SYSTEMS.md)).
- **Networking & reputação** ([07](07-NPC-AI-ARCHITECTURE.md)) destravam deals, talento, capital e M&A.
- **Macroeconomia** ([05](05-ECONOMY-DESIGN.md)) define o clima em que tudo opera.
- O **império** resultante é a expressão física e sistêmica da fantasia central ([01-Vision](01-PRODUCT-VISION.md)).

---

> **Anterior:** [← 05 — Economy Design](05-ECONOMY-DESIGN.md) · **Próximo:** [07 — NPC & Agent AI Architecture →](07-NPC-AI-ARCHITECTURE.md)

# 08 — Real Estate, Offices & Vehicle Systems

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 08 de 12 · Confidencial
> *Inclui: Real Estate Systems, Physical Offices, Vehicle Systems, Status as a System*

---

## 1. Filosofia: Ativos como Linguagem

> **Em MOGUL, o que você possui *fala por você*. Cada ativo físico é, ao mesmo tempo, um investimento financeiro, uma ferramenta operacional e uma declaração de status que o mundo lê e reage.**

Este documento cobre a manifestação **física e visível** da riqueza — a cristalização do Pilar I ("Viva o Império") e da cláusula "toda conquista deve ser visível no mundo" ([01-Vision](01-PRODUCT-VISION.md)). Três classes de ativos: **Imóveis** (onde você vive e opera), **Escritórios** (seu império feito espaço) e **Veículos** (status em movimento).

## 2. Imóveis (Real Estate)

Imóveis cumprem **quatro papéis** simultâneos, e o design os mantém entrelaçados:
1. **Moradia** — onde o avatar vive (status pessoal, bem-estar — ver [03-Gameplay](03-GAMEPLAY-DESIGN.md) §4).
2. **Operação** — onde as empresas funcionam (escritórios, lojas, fábricas, armazéns — ver §3).
3. **Investimento** — ativos que valorizam/desvalorizam, geram renda (aluguel), e podem ser "flipados".
4. **Status** — o endereço é uma das declarações de status mais fortes do jogo.

### 2.1 Ações sobre imóveis
| Ação | Descrição | Sistemas envolvidos |
|------|-----------|---------------------|
| **Comprar** | Adquirir imóvel pronto (residencial, comercial, industrial, terreno) | Finanças ([05](05-ECONOMY-DESIGN.md)), mercado imobiliário |
| **Construir** | Desenvolver do zero em terreno (incorporação) | Construção civil ([06](06-BUSINESS-SYSTEMS.md)), tempo, capex |
| **Reformar** | Melhorar/modernizar para valorizar ou reposicionar | Custo, tempo, ganho de valor/status |
| **Expandir** | Aumentar capacidade/área (crucial para escritórios — §3) | Capacidade operacional |
| **Visitar / Habitar** | Entrar e caminhar pelo espaço (diegese) | Presença física, [04-World](04-WORLD-DESIGN.md) |
| **Personalizar** | Decoração, mobília, arte, branding | Status, bem-estar, expressão (gancho cosmético — [12](12-BUSINESS-PLAN.md)) |
| **Alugar / Locar** | Gerar renda passiva como locador | Renda recorrente, gestão |
| **Vender / Flipar** | Realizar lucro de valorização | Mercado imobiliário, timing de ciclo |

### 2.2 O mercado imobiliário (dinâmico)
- Preços por **localização** ([04-World](04-WORLD-DESIGN.md): um andar em Sterling Heights ≠ um galpão em Ironside), **tipo**, **estado** e **ciclo econômico** ([05](05-ECONOMY-DESIGN.md)).
- **Valorização/desvalorização** reais: gentrificação (você pode *causá-la* comprando e reformando uma área de Ironside/Boroughs), boom/bolha imobiliária, recessão.
- **Renda de aluguel** como fluxo passivo (a base do arquétipo "rentista"/investidor imobiliário).
- **Incorporação** como negócio (construir para vender/alugar — ver setor Imobiliário/Construção em [06](06-BUSINESS-SYSTEMS.md)).

### 2.3 A jornada habitacional (status espacializado)
O lugar onde você mora é o **termômetro emocional** mais imediato da sua ascensão:

```
Quarto/apê minúsculo (Boroughs)  →  apê melhor  →  casa  →
loft no Grid  →  cobertura  →  mansão em Goldhaven  →  múltiplas residências globais
```

> Voltar ao apartamento inicial depois de rico é um dos momentos emocionais mais potentes planejados ([04-World](04-WORLD-DESIGN.md) §3.5). O "antes e depois" é design deliberado.

## 3. Escritórios Físicos — O Império Feito Espaço

> **Toda expansão da empresa precisa ser visual.** O escritório não é um ícone num menu — é um lugar por onde o jogador caminha e *vê* seu império crescer.

### 3.1 O escritório como narrativa de crescimento
A evolução do espaço de trabalho **é** a narrativa visual do sucesso:

| Fase | Espaço | O que o jogador vê |
|------|--------|--------------------|
| **1. Sobrevivência** | Mesa no quarto / um PC velho | Solidão, aperto, o computador antigo |
| **2. Crescimento** | Mesa em coworking → 1ª sala alugada (The Grid) | Os primeiros 2-3 funcionários, a primeira recepção |
| **3. Escala** | Andar próprio, várias equipes | Open space cheio, salas de reunião, áreas, recepção com sua marca |
| **4. Influência** | Sede corporativa (Sterling Heights), múltiplos andares | Lobby imponente, sua sala no topo, conselho |
| **5. Legado** | HQ-ícone na skyline + campi globais | Um prédio com seu nome; seu logo na cidade |

### 3.2 O escritório como espaço vivo
Ao caminhar pelo escritório, o jogador **vê e sente** a empresa:
- **Pessoas trabalhando** — funcionários (agentes — [07](07-NPC-AI-ARCHITECTURE.md)) em suas estações, em rotina; você reconhece quem é quem.
- **Salas de reunião** — onde acontecem entrevistas, negociações, conselhos (diegese — [01-Vision](01-PRODUCT-VISION.md)).
- **Recepção** — a primeira impressão; comunica status a visitantes (clientes/investidores percebem).
- **Equipamentos & ambiente** — qualidade da infra (afeta produtividade e moral — [06](06-BUSINESS-SYSTEMS.md) §5), e comunica prosperidade.
- **Clima/cultura visível** — um escritório feliz e produtivo *parece* diferente de um em crise (NPCs tensos, mesas vazias após demissões).

### 3.3 Escritório como sistema (não só cenário)
- **Capacidade** — o espaço limita quantos funcionários cabem; crescer exige expandir/mudar (gancho do loop de escala — [03](03-GAMEPLAY-DESIGN.md)).
- **Localização** — endereço afeta custo, prestígio, atração de talento e acesso (estar em Sterling impressiona investidores; The Grid atrai talento tech).
- **Layout & amenities** — investimentos que afetam produtividade, moral, retenção e status (afetam reputação com funcionários — [07](07-NPC-AI-ARCHITECTURE.md) §6).
- **Branding do espaço** — sua marca visível no ambiente (reforça reputação de marca — [06](06-BUSINESS-SYSTEMS.md) §9).
- **Personalização** — do funcional ao ostentatório; ganchos cosméticos premium ([12](12-BUSINESS-PLAN.md)).

## 4. Veículos — Status em Movimento

> **O veículo não é cosmético. Ele comunica status. Clientes percebem. Investidores percebem. NPCs percebem.**

### 4.1 Veículo como sinal social (a mecânica central)
Em MOGUL, o carro é um **sinalizador de status legível pelos agentes**. Ao te ver/encontrar, NPCs (Tier 2/3 — [07](07-NPC-AI-ARCHITECTURE.md)) **leem** seu veículo como evidência de sucesso, e isso **modula a interação**:
- **Primeiras impressões:** chegar a uma reunião num carro popular vs. num esportivo de luxo altera a predisposição do NPC (respeito, expectativa, termos de negociação).
- **Credibilidade:** um investidor avalia seu sucesso aparente; um cliente premium julga se você "pertence" ao mundo dele.
- **Coerência de status:** ostentar acima do seu nível real pode impressionar — ou soar como fraude/insegurança para NPCs perspicazes (leitura por Big Five — [07](07-NPC-AI-ARCHITECTURE.md)). Coerência entre status real e aparente é, ela mesma, um jogo.

> Isso operacionaliza a ideia de que **status é um recurso jogável**, não decoração. (Mesma lógica vale para roupas/aparência e companhia com quem você anda.)

### 4.2 A escada de veículos (curva de status)
```
Transporte público / a pé  →  carro usado/popular  →  sedã executivo  →
esportivo / SUV de luxo  →  carro com motorista  →  helicóptero  →  jato privado
```
- Cada degrau é uma **conquista visível** e desbloqueia/reforça acesso social.
- **Motorista** (NPC) libera o tempo do avatar (você trabalha/telefona enquanto se desloca — toca o recurso "tempo", [03](03-GAMEPLAY-DESIGN.md) §4).
- **Helicóptero/jato** ligam-se à mobilidade e expansão ([04-World](04-WORLD-DESIGN.md): heliponto nos rooftops; jato no MER → expansão global).

### 4.3 Veículo como ativo & utilidade
- **Ativo financeiro:** custo de compra, depreciação, manutenção, seguro — um *sink* de capital e de lifestyle ([05](05-ECONOMY-DESIGN.md) §7).
- **Frota corporativa:** veículos de empresa (logística, executivos) — ligam-se a operações ([06-Business](06-BUSINESS-SYSTEMS.md), setor Logística).
- **Colecionismo (endgame):** garagem de carros de luxo como troféu/legado e classe de ativo (e gancho cosmético premium — [12](12-BUSINESS-PLAN.md)).

## 5. Status como Sistema Unificado

Imóveis, escritórios, veículos — junto com **aparência/roupas**, **companhia social** e **reputação** ([07](07-NPC-AI-ARCHITECTURE.md)) — alimentam um **Status Score percebido** que os agentes leem:

```
Status Percebido = f(endereço, veículo, vestuário, companhia,
                      reputação pública, marca pessoal, contexto)
```

- **Lido pelos agentes** para modular interações sociais e de negócios ([07](07-NPC-AI-ARCHITECTURE.md) §5).
- **Diegético:** nunca mostrado como "número de status" cru; é *sentido* via como o mundo te trata (ver [09-UX-UI](09-UX-UI.md)).
- **Contextual:** o status "certo" varia por círculo (ostentação funciona em Goldhaven; em The Grid, autenticidade tech pode valer mais).
- **Tensão:** investir em status consome capital que poderia ir para o negócio — uma escolha estratégica real, não vaidade gratuita.

## 6. Conexões de Produção
- **Tecnologia:** interiores e exteriores via Nanite/Lumen/PCG; alta proporção de espaços acessíveis (diegese). Modularidade + PCG para escala, autorais para marcos ([04-World](04-WORLD-DESIGN.md) §7, [10-Tech](10-TECHNICAL-ARCHITECTURE.md)).
- **Monetização:** customização de imóveis, veículos, roupas e arte de escritório são as **principais avenidas de cosméticos premium não-pay-to-win** ([12-Business](12-BUSINESS-PLAN.md)).
- **Content pipeline:** catálogos de mobília/veículos/roupas são conteúdo escalável e expansível via Live Ops ([10-Tech](10-TECHNICAL-ARCHITECTURE.md), [12](12-BUSINESS-PLAN.md)).

---

> **Anterior:** [← 07 — NPC & Agent AI](07-NPC-AI-ARCHITECTURE.md) · **Próximo:** [09 — UX/UI Design →](09-UX-UI.md)

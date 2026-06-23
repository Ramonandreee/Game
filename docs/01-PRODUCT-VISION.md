# 01 — Product Vision & Core Pillars

> *Project ATLAS / MOGUL — Bíblia de Pré-Produção*
> Documento 01 de 12 · Confidencial

---

## 1. A Visão Fundamental

> **O jogador não administra uma empresa. O jogador vive a vida de um empresário.**

Esta distinção é **absoluta** e governa cada decisão de design em MOGUL. Não é uma frase de marketing — é uma restrição de engenharia e de design que filtra todo o backlog.

O que isso significa, concretamente:

| NÃO é MOGUL | É MOGUL |
| --- | --- |
| Abrir um menu para "contratar funcionário" | Entrevistar um candidato sentado à sua frente, ler a linguagem corporal, negociar salário |
| Ver um número de "satisfação do cliente" | Jantar com o cliente, perceber que ele está distante, descobrir que um concorrente o está cortejando |
| Clicar "construir escritório" | Comprar um andar vazio, contratar arquiteto, ver as paredes subirem, caminhar por ele inaugurado |
| Uma barra de "reputação" | Ser reconhecido (ou ignorado) ao entrar num clube; ler seu nome num jornal; ser vaiado após um escândalo |
| Um botão "investir em ações" | Receber uma ligação de um broker, avaliar o pitch, apertar a mão |

A regra de ouro: **se uma ação importante puder ser reduzida a um clique de menu sem perda de fantasia, ela está mal projetada.** A interface existe para *suportar* a vida, não para *substituí-la*. (Ver [09-UX-UI](09-UX-UI.md) sobre interface diegética.)

## 2. O que o jogador deve sentir

MOGUL é, antes de tudo, uma **máquina de emoções**. O design existe para produzir, em sequência e em camadas, sete sensações:

1. **Ambição** — sempre haver um próximo degrau visível e desejável.
2. **Crescimento** — sentir-se mais capaz, mais rico, mais conectado a cada sessão.
3. **Poder** — perceber que o mundo se curva às suas decisões.
4. **Prestígio** — ser *visto* e *reconhecido* pelo mundo.
5. **Risco** — ter algo real a perder; sentir o estômago apertar numa aposta.
6. **Fracasso** — perder de verdade, e que isso signifique algo (sem ser punitivo a ponto de afastar).
7. **Conquista** — o alívio e o orgulho de superar — tornados **visíveis e permanentes** no mundo.

> **Toda conquista deve ser visível no mundo. Todo erro deve gerar consequências.**

Essa é a cláusula de "verificação emocional". Se uma conquista não tem manifestação física/social no mundo (um prédio novo, um carro, uma manchete, um NPC que muda de atitude), o sistema de recompensa falhou. Se um erro não tem consequência propagante, o sistema de risco falhou.

## 3. A jornada emocional — as cinco fases

A espinha dorsal de MOGUL é uma curva emocional de cinco atos. Cada fase tem uma **fantasia dominante**, um **conjunto de mecânicas habilitadas**, um **estado de mundo** e um **marco de transição**. (Aprofundado em [03-Gameplay-Design](03-GAMEPLAY-DESIGN.md).)

### Fase 1 — Sobrevivência
*Fantasia: "Será que eu consigo sair do zero?"*
- **Estado:** sem dinheiro, apartamento minúsculo, computador antigo, poucos contatos, poucas oportunidades.
- **Tensão:** contas vencendo, escolhas de subsistência, cada real importa.
- **Mecânicas habilitadas:** freelancing/serviços, networking de baixo nível, gestão de tempo e energia pessoal.
- **Marco de saída:** primeira empresa formalizada e lucrativa.

### Fase 2 — Crescimento
*Fantasia: "Está funcionando — eu posso construir algo."*
- **Estado:** primeiros clientes, primeiros funcionários, primeiro escritório real, primeiros investimentos.
- **Mecânicas:** contratação, delegação inicial, marketing, primeiras linhas de crédito.
- **Marco de saída:** primeira rodada de investimento externo (anjo/seed).

### Fase 3 — Escala
*Fantasia: "Eu não faço mais o trabalho — eu comando."*
- **Estado:** diversas empresas, gerentes, sócios, investidores, primeiras aquisições.
- **Mecânicas:** holdings, org charts, M&A, conselhos, sinergias entre empresas.
- **Marco de saída:** primeira aquisição de uma empresa concorrente relevante.

### Fase 4 — Influência
*Fantasia: "O mundo me conhece e me ouve."*
- **Estado:** reconhecimento nacional, presença na mídia, grandes eventos, influência indireta sobre o mercado e a política.
- **Mecânicas:** relações públicas, lobby indireto, manipulação de mercado, eventos de gala, IPOs.
- **Marco de saída:** tornar-se uma figura pública que *move o mercado* com declarações.

### Fase 5 — Legado
*Fantasia: "O que sobra de mim?"*
- **Estado:** conglomerados, fundações, impacto global, sucessão empresarial.
- **Mecânicas:** filantropia, criação de instituições, formação de herdeiros/sucessores, "endgame" de influência.
- **Marco de saída:** o jogador define seu legado — e pode "passar o bastão" (new game+ geracional).

> A curva é projetada para que **a sensação de poder cresça monotonicamente**, mas o **risco cresça junto** — você tem cada vez mais a perder. O fracasso na Fase 4 dói muito mais do que na Fase 1, e é exatamente esse o ponto.

## 4. Os Três Pilares de Design

Tudo em MOGUL serve a um destes três pilares. Eles são a constituição do projeto.

### Pilar I — "Viva o Império" (Imersão Diegética)
**Tudo é físico, visível e vivido em primeira/terceira pessoa.**
- Sem planilhas frias como interface primária; dados existem *no mundo* (telas in-game, conversas, documentos, ambientes).
- Cada conquista tem manifestação física: imóveis, veículos, escritórios, roupas, arte, manchetes.
- O corpo do avatar importa: presença, aparência, saúde, energia, status comunicado.

*Implicações:* prioriza investimento em world-building, MetaHuman, animação, áudio e UI diegética.

### Pilar II — "O Mundo Reage" (Simulação Viva e Consequente)
**O mundo existe com ou sem o jogador, e responde a cada ação.**
- Economia macro autônoma + empresas concorrentes-IA que agem sozinhas.
- NPCs agênticos com memória persistente: lembram favores, traições, negociações por anos.
- Reputação multidimensional que abre e fecha portas reais.
- Consequências propagantes: uma traição vaza, muda reputações, fecha oportunidades, cria inimigos.

*Implicações:* prioriza investimento em IA agêntica, simulação econômica, sistema de eventos e persistência.

### Pilar III — "Da Sobrevivência ao Legado" (Fantasia de Poder de Longo Arco)
**Uma curva de progressão que vai do nada ao topo e à sucessão.**
- Sempre há um próximo degrau aspiracional e visível.
- Múltiplas formas de "vencer": magnata, investidor global, dono de holding, shark investor, filantropo, figura pública.
- Endgame focado em **influência e legado**, não em um número de dinheiro.

*Implicações:* prioriza investimento em sistemas de longo prazo, meta-progressão, endgame e replayability.

## 5. O Princípio de Design Mestre (o "Pillar Gate")

> **Todo sistema, feature ou conteúdo precisa responder afirmativamente à pergunta:**
> ## *"Isso faz o jogador sentir que está construindo um império?"*
> **Se a resposta for não, é cortado — não importa quão 'legal' seja.**

Operacionalização do gate (usado em todo greenlight de feature):

1. **Qual fantasia/sensação** (das 7) este sistema serve?
2. **Como ele se manifesta visivelmente** no mundo? (Se não se manifesta, repensar — viola Pilar I.)
3. **Qual consequência** ele gera quando dá certo e quando dá errado? (Se nenhuma, viola Pilar II.)
4. **Como ele evolui** entre as 5 fases? (Se é estático, provavelmente viola Pilar III.)
5. **Custo de produção vs. retorno emocional** — cabe no budget de escopo?

Uma feature só entra no backlog de produção se passar pelos cinco. Este gate é a principal **defesa contra feature creep** — o maior risco do projeto (ver [12-Business-Plan](12-BUSINESS-PLAN.md#risk-analysis)).

## 6. Tom, fantasia e posicionamento criativo

- **Tom:** realismo aspiracional com mordida satírica leve. Levamos a simulação a sério, mas o mundo tem humor (mídia sensacionalista, modismos de startup, gurus de "hustle").
- **Fantasia central:** *o self-made mogul* — a ascensão do nada ao topo por mérito, manha, networking e risco.
- **Maturidade:** adulto (Mature 17+). Temas de ganância, traição, poder, vício em trabalho, custo pessoal do sucesso. O jogo **não moraliza**, mas **mostra consequências** (relações que se desgastam, saúde, solidão no topo).
- **Referências de qualidade (benchmark de execução):** Rockstar (densidade/produção), CD Projekt Red (mundo/narrativa), Larian (consequência/reatividade), Paradox (profundidade sistêmica), Epic (tecnologia/escala).
- **Não-objetivos:** não é um clicker idle; não é um jogo de planilha; não é pay-to-win; não é um sandbox sem propósito.

## 7. Bússola de Design (heurísticas de decisão)

Quando duas opções de design competem, decidimos por esta ordem de prioridade:

1. **Fantasia > Realismo.** Simulamos a *sensação* de ser um magnata, não um curso de contabilidade. Realismo é ferramenta, não meta.
2. **Consequência > Conveniência.** Atrito que cria significado é bom; atrito gratuito é cortado.
3. **Sistemas > Scripts.** Preferimos emergência sistêmica a conteúdo roteirizado e único (mas usamos narrativa roteirizada como "tempero" e tutorial).
4. **Legibilidade > Profundidade oculta.** Profundidade sem legibilidade é frustração; o jogador deve sempre entender *por que* algo aconteceu.
5. **Visível > Abstrato.** Entre duas soluções equivalentes, escolhemos a que tem corpo no mundo.

## 8. Definição de Sucesso (estrelas-guia)

O projeto é bem-sucedido se, no lançamento:

- **Emocional:** playtesters relatam ter "sentido a ascensão" e ter "se importado" com um NPC ou com o destino de uma empresa.
- **Sistêmico:** a economia e os agentes produzem histórias emergentes que jogadores compartilham organicamente (clipes, posts).
- **Comercial:** atinge break-even no ano 1 (ver [12](12-BUSINESS-PLAN.md)).
- **Cultural:** estabelece "AAA Life-Business Sim" como categoria reconhecida, com MOGUL como referência.

---

> **Anterior:** [← 00 — Executive Summary](00-EXECUTIVE-SUMMARY.md) · **Próximo:** [02 — Market, Audience & Competition →](02-MARKET-ANALYSIS.md)

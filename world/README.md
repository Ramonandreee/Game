# MOGUL — Meridian City (mundo 3D navegável)

> Uma fatia jogável da Meridian City do [World Design](../docs/04-WORLD-DESIGN.md), em primeira pessoa, no navegador. A camada "presença física / Pilar I" do GDD, tornada real e caminhável.

## ▶ Como jogar

1. Abra **`world/index.html`** no navegador (Chrome/Edge/Firefox recentes).
2. **Clique** para entrar (ativa o controle de mouse / pointer lock).
3. Ande pela cidade e interaja.

| Tecla | Ação |
|-------|------|
| `W A S D` | Andar |
| `Shift` | Correr |
| Mouse | Olhar |
| `E` | Interagir (quando o aviso aparece) / entrar e sair do carro |
| `V` | Alternar câmera **1ª ↔ 3ª pessoa** (estilo GTA) |
| `E` | **Entrar em qualquer carro** da rua / interagir / sair do carro |
| `R` | Chuva on/off · `P` modo foto · `N` trocar rádio |
| `Tab` | Abrir/fechar o celular (MeridianOS) |
| `M` | Ligar/desligar o som |
| `Esc` | Liberar o cursor |
| `[` `]` | Ajustar **exposição** (claro/escuro) ao vivo |
| `-` `=` | Ajustar **bloom** (brilho das luzes) ao vivo |
| `B` | Ligar/desligar bloom |

### 📱 iPhone / mobile (web app)
Totalmente jogável no iPhone **em paisagem**, como web app nativo:
- **Joystick** (canto inferior esquerdo) anda/dirige · **arraste** na tela para olhar
- Botões à direita: **E** (interagir / entrar e sair do carro), **RUN** (correr), **☰** (celular)
- Adicione à **Tela de Início** (Safari → Compartilhar → "Adicionar à Tela de Início") para abrir em tela cheia, sem barras (PWA: `manifest.webmanifest` + `icon.svg`, orientação paisagem, respeita o notch/safe-area, sem zoom acidental)
- Em **retrato** aparece um aviso para girar o aparelho. O desktop (teclado/mouse) continua igual.

> 🎨 **Visual realista:** tone mapping cinematográfico (ACES), **bloom** (janelas e luzes que brilham de verdade), **reflexos** via environment map (carro/vidro/asfalto), névoa atmosférica e **postes de luz**. Use as teclas `[ ] - = B` para calibrar o look ao seu gosto. Se o bloom não for suportado, o jogo cai automaticamente no render normal (sem travar).

> ⚠️ **Precisa de internet na primeira vez** — o mundo carrega a engine **Three.js** de um CDN. Se abrir offline, aparece um aviso. (O simulador em [`../game/index.html`](../game/index.html) roda 100% offline.)

## O que fazer na cidade

- **Pessoas com anel dourado** → aproxime e `E` para **fazer networking** (investidores, talentos, clientes). Cultive a relação; depois peça investimento, recrute, ou feche contrato.
- **The Foundry** (marcador azul, no The Grid) → **entre no seu escritório**: um interior 3D por onde você caminha. Dentro: a **mesa de comando** abre o painel de negócios (fundar/contratar/operar) e a **saída** te devolve à rua. O escritório **cresce com a empresa** — mais funcionários = mais mesas e gente trabalhando.
- **Seu carro** (marcador vermelho, perto do apartamento) → `E` para **entrar e dirigir** pela cidade (`WASD`, `Shift` acelera). `E` de novo para sair.
- **Meridian Exchange** (marcador dourado, em Sterling Heights) → ver o **mercado** (ciclo, juros).
- **Apex Club** (marcador roxo, em Goldhaven) → networking de elite (exige reputação/fase).
- **Seu apartamento** (marcador verde, nos Boroughs) → **dormir / encerrar o dia** (avança a simulação).
- **`Tab`** abre o **MeridianOS** (você, império, mercado, rede, feed).
- **Minimapa** (canto superior direito) mostra você, sua direção e os pontos de interesse. **Trânsito** e multidões dão vida às ruas; **outdoors** exibem a sua maior empresa conforme você cresce.

## Como mapeia ao GDD

| No mundo 3D | Documento |
|-------------|-----------|
| Cidade em distritos, verticalidade, dia/noite, multidões | [04-World](../docs/04-WORLD-DESIGN.md) |
| Caminhar em 1ª pessoa, presença física, status sentido | [01-Vision](../docs/01-PRODUCT-VISION.md) Pilar I, [09-UX](../docs/09-UX-UI.md) |
| Networking presencial (aproximar, conversar, cultivar) | [07-AI](../docs/07-NPC-AI-ARCHITECTURE.md) §5 |
| Empresas, setores, contratação, mercado, eventos | [05](../docs/05-ECONOMY-DESIGN.md), [06](../docs/06-BUSINESS-SYSTEMS.md) |
| MeridianOS como hub diegético | [09-UX](../docs/09-UX-UI.md) §3.1 |
| Engine 3D, day/night, instancing de multidão | [10-Tech](../docs/10-TECHNICAL-ARCHITECTURE.md) |

## Honestidade sobre o que isto é (e não é)

Isto é uma **fatia 3D estilizada em tempo real (WebGL/Three.js)** — para você *andar pela cidade* e sentir o mundo. **Não** é o build AAA final descrito no [doc 10](../docs/10-TECHNICAL-ARCHITECTURE.md): não tem Unreal Engine 5.6, Nanite, Lumen, MetaHumans, nem diálogo por LLM. Aquilo é a produção de ~6 anos / ~US$195M do [doc 11](../docs/11-PRODUCTION-PLAN.md) — que nenhuma sessão de chat produz. O objetivo aqui é **provar a sensação de presença** no mundo, com a economia já validada rodando por baixo.

## Notas técnicas
- **Stack:** Three.js (r0.161 via CDN/importmap), arquivo único, sem build.
- **Performance:** multidão e prédios via `InstancedMesh`; fog para profundidade; ciclo dia/noite por interpolação de paletas. Roda em hardware modesto.
- **Robustez:** detector de falha de carregamento (offline/CDN) e overlay de erro — você nunca fica numa tela preta sem explicação.
- **Economia:** mesma lógica balanceada do protótipo 2D; validada por simulação headless.

## ✨ Inspiração GTA (PC)
- **Câmera em 3ª pessoa** com avatar visível (tecla `V` alterna com 1ª pessoa) — a "cara" de GTA
- **Pegar qualquer carro**: há vários carros pela cidade; chegue perto e `E` para entrar e dirigir (sai com `E`)
- **Objetivos / missões**: sempre há um alvo (blip **amarelo**) ligado aos negócios; algumas são **em duas etapas com uma escolha** (negociar duro vs. fechar amigável). Conclua → caixa/reputação → surge o próximo
- **Radar circular** estilo GTA que **gira com você**, com blips (objetivo, carros, marcos)
- **Clima dinâmico**: chuva (tecla `R` ou automático) com **asfalto molhado refletindo** as luzes
- **Modo foto** (`P`): esconde a interface para capturas
- **Rádio** (`N`): estações sintetizadas; **áudio** com ambiente da cidade e **motor do carro** (acelera junto); `M` muda
- **Mais vida**: pedestres (corpo+cabeça) que **fogem do carro**, trânsito que **para em "semáforos"**, árvores e postes — tudo brilhando com o bloom à noite

> Padrões de visual: **exposição 1.75**, **bloom 0.20** (ajustáveis ao vivo com `[ ] - =`). Direção do carro corrigida (esquerda/direita).

## Já implementado neste mundo
- ✅ **Interiores de escritório** que você percorre e que **crescem com a empresa** ([08-Assets](../docs/08-ASSETS-SYSTEMS.md)).
- ✅ **Carro dirigível** (status + traversal), **trânsito**, **outdoors da sua marca**, **minimapa/bússola**.
- ✅ Cidade em distritos, ciclo dia/noite, multidões, networking presencial, economia viva, 5 fases.

> Validação: sintaxe OK; economia headless sem regressão; **execução headless de todo o JS 3D** (boot, render loop, escritório, direção, trânsito, outdoors, minimapa) sem erros. *Renderização visual em si só dá para conferir no navegador* — por isso há overlay de erro e try/catch por frame (nunca tela preta muda).

## Próximos passos sugeridos
1. **Mais interiores** (recepção, salas de reunião, andares por nível de fase) e NPCs nomeados dentro do escritório.
2. **Jato no aeroporto** (expansão global) e mais veículos/garagem de status.
3. **Port para Unreal Engine 5.6** — o scaffold real **já existe** em [`../ue5`](../ue5) (Economy/Agent/Save em C++, plugins Mass/PCG/GAS). Próximo: Player Character + Mass crowds + PCG no World Partition.

*Caminhe — e agora dirija — pela cidade que você vai conquistar. 🌆*

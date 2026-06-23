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
| `E` | Interagir (quando o aviso aparece) |
| `Tab` | Abrir/fechar o celular (MeridianOS) |
| `Esc` | Liberar o cursor |

> ⚠️ **Precisa de internet na primeira vez** — o mundo carrega a engine **Three.js** de um CDN. Se abrir offline, aparece um aviso. (O simulador em [`../game/index.html`](../game/index.html) roda 100% offline.)

## O que fazer na cidade

- **Pessoas com anel dourado** → aproxime e `E` para **fazer networking** (investidores, talentos, clientes). Cultive a relação; depois peça investimento, recrute, ou feche contrato.
- **The Foundry** (marcador azul, no The Grid) → **painel de negócios**: fundar empresas, contratar, tocar a operação.
- **Meridian Exchange** (marcador dourado, em Sterling Heights) → ver o **mercado** (ciclo, juros).
- **Apex Club** (marcador roxo, em Goldhaven) → networking de elite (exige reputação/fase).
- **Seu apartamento** (marcador verde, nos Boroughs) → **dormir / encerrar o dia** (avança a simulação).
- **`Tab`** abre o **MeridianOS** (você, império, mercado, rede, feed).

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

## Próximos passos sugeridos (rumo ao doc 10/11)
1. **Interiores** do escritório que crescem com a empresa (caminhar entre as mesas — [08-Assets](../docs/08-ASSETS-SYSTEMS.md)).
2. **Veículos** dirigíveis e o jato no aeroporto (expansão global).
3. **Port para Unreal Engine 5.6**: posso gerar o *scaffold* real do projeto (`.uproject`, módulos C++ do Economy Engine / Agent System / Save, plugins Mass/PCG/MetaHuman) — o ponto de partida de engine do [doc 10](../docs/10-TECHNICAL-ARCHITECTURE.md). É só pedir.

*Caminhe pela cidade que você vai conquistar. 🌆*

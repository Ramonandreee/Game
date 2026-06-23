# MOGUL — Protótipo Jogável (Vertical Slice)

> O "feel + economy prototype" do Ano 1 do [plano de produção](../docs/11-PRODUCTION-PLAN.md), jogável no navegador, sem dependências.

## ▶ Como jogar

1. Baixe / abra **`game/index.html`** no seu navegador (Chrome, Firefox, Safari, Edge — qualquer um).
   - Duplo-clique no arquivo já funciona (é 100% offline, um único arquivo).
2. Digite seu nome, escolha uma origem e clique **"Começar a jornada"**.
3. Cada dia você tem **energia** (≈ 3 ações). Gaste em ações na aba **Hoje**, depois clique **"Encerrar o dia"**.
4. O save é **automático** (no navegador). Para recomeçar do zero: link "reiniciar" no rodapé.

> Dica de sobrevivência: no início, **freelas pagam as contas**. Junte caixa antes de fundar a primeira empresa — e não suba o padrão de vida cedo demais.

## O que está implementado (e como mapeia ao GDD)

| Sistema no protótipo | Documento do GDD |
|----------------------|------------------|
| 5 fases emocionais (Sobrevivência → Legado) com marcos | [03-Gameplay](../docs/03-GAMEPLAY-DESIGN.md), [01-Vision](../docs/01-PRODUCT-VISION.md) |
| Daily loop: energia, estresse, ações, encerrar o dia | [03-Gameplay](../docs/03-GAMEPLAY-DESIGN.md) §2 |
| Fundar/operar/vender empresas · 10 setores com economia própria | [06-Business](../docs/06-BUSINESS-SYSTEMS.md) |
| Funcionários como agentes (competência, ambição, traços, felicidade) | [07-AI](../docs/07-NPC-AI-ARCHITECTURE.md) §3, [06](../docs/06-BUSINESS-SYSTEMS.md) §5 |
| Agentes pedem aumento, viram sócios, saem e abrem concorrentes | [06-Business](../docs/06-BUSINESS-SYSTEMS.md) §5.2, [07](../docs/07-NPC-AI-ARCHITECTURE.md) |
| Memória dos contatos ("lembra de você por…") | [07-AI](../docs/07-NPC-AI-ARCHITECTURE.md) §3.3 |
| Networking (café → coworking → Apex Club), relações que abrem portas | [07-Networking](../docs/07-NPC-AI-ARCHITECTURE.md) §5 |
| Reputação multidimensional (mercado, como chefe, pública) | [07-Reputação](../docs/07-NPC-AI-ARCHITECTURE.md) §6 |
| Economia viva: ciclos boom/recessão, juros, multiplicador de mercado | [05-Economy](../docs/05-ECONOMY-DESIGN.md) |
| Status físico: apartamento e carro mudam como o mundo te trata | [08-Assets](../docs/08-ASSETS-SYSTEMS.md) |
| Eventos com escolhas e consequências (aquisição, roubo de talento, imprensa…) | [05](../docs/05-ECONOMY-DESIGN.md), [07](../docs/07-NPC-AI-ARCHITECTURE.md) |
| Interface diegética (MeridianOS-like), patrimônio sentido | [09-UX/UI](../docs/09-UX-UI.md) |

## O que **ainda não** está aqui (é um protótipo)

Este é o protótipo de *sistemas e sensação*, não o jogo AAA final. **Não** inclui: o mundo 3D em Unreal Engine, MetaHumans, diálogo por LLM, o mundo aberto navegável, multiplayer. Esses são o trabalho de produção descrito em [10-Tech](../docs/10-TECHNICAL-ARCHITECTURE.md) e [11-Produção](../docs/11-PRODUCTION-PLAN.md). O objetivo aqui é **provar que o loop é divertido** antes de escalar a produção — exatamente o que o GDD prescreve.

## Notas técnicas

- **Stack:** HTML/CSS/JS puro, arquivo único, zero dependências, zero build.
- **Balanceamento:** a economia foi afinada por **simulação headless** (centenas de dias rodados sem render, caçando instabilidades) — o "headless econ sim" de [10-Tech](../docs/10-TECHNICAL-ARCHITECTURE.md) §4.
- **Qualidade:** as rotas de UI (render, modais, eventos, game over) foram validadas por testes automatizados de fumaça.
- **API de teste:** a lógica é exposta em `window.MOGUL` (inclui hooks `_*` para simulação), permitindo dirigir o jogo por script.

## Roadmap curto do protótipo (próximos passos sugeridos)
- M&A jogável (comprar concorrentes, não só vender) e holdings/sinergias.
- Gerentes-IA para delegação (a "economia da atenção" do endgame — [03](../docs/03-GAMEPLAY-DESIGN.md) §8).
- Mais profundidade por setor (mecânicas próprias reais, não só parâmetros).
- IPO / mercado de capitais ([05](../docs/05-ECONOMY-DESIGN.md) §8).
- Mapa visual dos distritos de Meridian.

*Divirta-se construindo seu império. 🏙️*

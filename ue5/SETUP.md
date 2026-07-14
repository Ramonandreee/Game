# 🚀 Guia de Setup — Abrir o MOGUL na Unreal Engine 5.6 (passo a passo)

> Para quem **nunca abriu a Unreal**. Tempo total: ~1h (a maior parte é download/instalação).
> Já tem a UE 5.6 instalada pelo Epic Launcher? Ótimo — comece no Passo 1.

---

## Passo 1 — Instalar o Visual Studio 2022 (o compilador de C++)

O MOGUL é um projeto **C++** (é assim que projetos AAA são feitos). A Unreal precisa de um
compilador para transformar o código em jogo — e ele não vem com a engine.

1. Baixe o **Visual Studio 2022 Community** (gratuito): <https://visualstudio.microsoft.com/pt-br/vs/community/>
2. Ao rodar o instalador, na tela de **Cargas de Trabalho (Workloads)**, marque:
   - ✅ **Desenvolvimento de jogos com C++** *(Game development with C++)*
   - ✅ **Desenvolvimento para desktop com .NET** *(.NET desktop development)*
3. Clique **Instalar** e aguarde (é grande: ~15–30 GB; pode deixar baixando).

> 🍎 **No Mac:** em vez do Visual Studio, instale o **Xcode** pela App Store.

## Passo 2 — Baixar o projeto do GitHub

O jeito mais simples, sem instalar nada:

1. Acesse **github.com/Ramonandreee/Game** (logado na sua conta)
2. Botão verde **`<> Code`** → **Download ZIP**
3. Extraia para uma pasta de **caminho curto e sem acentos/espaços**, ex.: `C:\Dev\MOGUL`
   *(evite Área de Trabalho/OneDrive/pastas com acento — o build do Windows não gosta)*

> Alternativa para quem usa Git: `git clone https://github.com/Ramonandreee/Game.git C:\Dev\MOGUL`

## Passo 3 — Abrir o projeto (a primeira compilação)

1. Entre na pasta **`C:\Dev\MOGUL\ue5\`**
2. **Dê dois cliques em `MOGUL.uproject`**
3. Vai aparecer: *"The following modules are missing or built with a different engine version:
   MOGUL. Would you like to rebuild them now?"* → clique **Yes**
4. Aguarde a compilação (primeira vez: **2–10 min**, janela sem muita coisa na tela — é normal)
5. O editor da Unreal abre. Na primeira abertura ele ainda **compila shaders** em segundo
   plano (contador no canto inferior direito, pode passar de mil) — deixe terminar, é só na primeira vez.

**Se aparecer erro** em vez do editor: veja o [Passo 6](#passo-6--deu-erro-me-mande-que-eu-corrijo).

## Passo 4 — Ver a Cena Meridian 🌇

1. No editor: **File → New Level → Empty Level** (nível vazio mesmo)
2. Aperte **Play** (botão ▶ na barra superior, ou `Alt+P`)
3. O GameMode detecta que o nível não tem céu e **spawna a Meridian sozinho**:
   sol de fim de tarde, céu físico, nuvens volumétricas, névoa — e a cidade em
   greybox com os distritos (torres com pódio em Sterling, galpões em Ironside…)
4. **Voe**: `WASD` move, mouse olha. Se nascer "dentro" do chão, voe para cima.
5. `Esc` sai do Play. Experimente também selecionar o ator `MogulCityBootstrap`
   no Outliner (durante o Play) e mudar o **RandomSeed** — a cidade regenera.

> 💡 Dica: salve o nível (`Ctrl+S`) como `Meridian` dentro de `Content/Maps/` para
> não recriar da próxima vez.

## Passo 5 — O que fazer depois (o caminho do fotorrealismo)

Na ordem que dá mais resultado por esforço (detalhes no [README](README.md) e no [doc 13](../docs/13-ART-DIRECTION.md)):

1. **Fab / Quixel Megascans** (grátis para UE): janela **Window → Fab** no editor →
   baixe materiais de asfalto/concreto/vidro e kits de fachada → arraste na cena
2. **MetaHuman**: crie um humano fotorrealista em <https://metahuman.unrealengine.com>
   e importe via Quixel Bridge — é o "degrau 3" dos personagens
3. Substituir os cubos do greybox por meshes com **Nanite** (basta importar que a UE ativa)
4. O rig de luz/post que já está no projeto continua valendo — é ele que faz tudo "parecer foto"

## Passo 6 — Deu erro? Me mande, que eu corrijo

É **normal e esperado** aparecer erro de compilação na primeira vez em projeto C++ novo.
O fluxo de trabalho é: você me cola o erro → eu corrijo o código → você baixa de novo (ou dá `git pull`).

Onde pegar o texto do erro:
- O **popup** que aparecer (print ou copie o texto), **ou**
- O arquivo de log: `ue5\Saved\Logs\MOGUL.log` (abra no Bloco de Notas, copie o final), **ou**
- Se compilar pelo Visual Studio: a aba **Output/Saída**

Cole aqui na nossa conversa que eu ajusto na hora.

### Problemas comuns

| Sintoma | Causa/solução |
|---|---|
| Dois cliques no `.uproject` não faz nada / abre programa errado | Abra o **Epic Games Launcher → Unreal Engine → Library → Launch 5.6** e depois **Browse** até o `.uproject`; ou clique-direito no `.uproject` → *Switch Unreal Engine version…* → 5.6 |
| "Would you like to rebuild them now?" → **No** apareceu de novo | Sempre **Yes**. Se falhar, é erro de compilação → Passo 6 |
| Erro citando "Visual Studio", "MSVC", "SDK" ou "toolchain" | O Passo 1 não está completo — reabra o instalador do VS (*Modificar*) e confira as duas cargas de trabalho |
| Compilou mas o Play mostra tela preta | Confira se criou **Empty Level** e deu Play; e espere os shaders compilarem |
| Editor muito lento na 1ª vez | Compilação de shaders em background — só na primeira abertura |

---

*Quando o editor abrir com a Meridian ao pôr do sol, me avise — daí seguimos para Player Character, materiais PBR e MetaHumans.* 🌇

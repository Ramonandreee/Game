# CLAUDE.md — Guia do Projeto para instâncias do Claude

> Este arquivo faz parte do clone do repositório. Qualquer sessão do Claude Code (de qualquer
> colaborador) que abrir este projeto deve ler e seguir o que está aqui, para mantermos
> consistência entre contas/sessões diferentes.

## O que é este projeto

**MOGUL** (codinome *Project ATLAS*) — um simulador de vida empresarial em mundo aberto de
ambição AAA. O repositório contém **duas coisas**:

1. **A bíblia de design** (`docs/`) — especificação de pré-produção completa (13 documentos + glossário).
2. **Protótipos jogáveis** — provas de conceito que rodam no navegador:
   - `game/index.html` — protótipo de **sistemas** (2D, 100% offline, sem deps).
   - `world/index.html` — **Meridian City em 3D** navegável (Three.js via CDN).

> A fonte canônica de fatos (nome, escopo, orçamento, plataformas) é o topo do [`README.md`](README.md).
> Mudou um fato lá → propague para os documentos afetados.

## Estrutura

```
README.md              Índice mestre + fatos canônicos
docs/00..12            A bíblia (visão, mercado, gameplay, mundo, economia, negócios,
                       IA, ativos, UX, técnica, produção, plano de negócio)
docs/GLOSSARY.md       Termos canônicos
game/                  Protótipo 2D de sistemas (+ game/README.md)
world/                 Mundo 3D navegável (+ world/README.md)
CONTRIBUTING.md        Como colaborar (humanos + IA, via GitHub/PRs)
```

## Princípios de design que governam TODA decisão

1. **Pillar Gate** (ver [docs/01](docs/01-PRODUCT-VISION.md) §5): toda feature/conteúdo precisa
   responder *"isso faz o jogador sentir que está construindo um império?"*. Se não, corta.
2. **Diegese (Pilar I):** nada de "planilha gamificada". Ações importantes são *vividas*, não viram menu cru.
3. **O mundo reage (Pilar II):** economia + agentes vivem com ou sem o jogador; ações têm consequência persistente.
4. **Da sobrevivência ao legado (Pilar III):** sempre há um próximo degrau aspiracional.
5. **Bússola:** Fantasia > Realismo · Consequência > Conveniência · Sistemas > Scripts · Legibilidade > Profundidade oculta · Visível > Abstrato.

## Convenções

- **Idioma:** documentação e textos de jogo em **PT-BR**; termos técnicos de indústria em inglês quando for o padrão. Código/comentários técnicos podem ser em inglês.
- **Protótipos:** manter **single-file, sem build, sem dependências** (o 3D usa Three.js via CDN/importmap — é a única exceção, e precisa ter fallback de erro/offline).
- **Economia é data-driven e balanceada por simulação** — ver "Validação" abaixo.

## Validação antes de commit/push (OBRIGATÓRIO para mudanças nos protótipos)

Não faça push de protótipo sem validar. O padrão usado neste repo:

1. **Sintaxe:** extrair o `<script>` do HTML e rodar `node --check` (para o 3D, salvar como `.mjs`).
2. **Economia headless:** extrair a lógica de economia, stubar `document`/`localStorage`, e rodar
   centenas de "dias" simulados verificando que (a) não lança exceção, (b) progride pelas 5 fases,
   (c) falência é possível mas não garantida (sobrevivência tensa, justa).
3. **UI smoke test:** stubar o DOM e exercitar render/modais/eventos/game-over sem lançar.

> Exemplos desses harnesses já foram usados nos commits de `game/` e `world/`. Replicar o mesmo
> padrão. Use o diretório scratchpad da sessão para arquivos temporários, **nunca** comite testes
> temporários no repo.

## Git / colaboração

- **Branch por contribuidor/tarefa.** Não trabalhar direto na default branch. Ver [CONTRIBUTING.md](CONTRIBUTING.md).
- **Commits descritivos** (pt-BR ok), escopo com prefixo: `docs:`, `feat(game):`, `feat(world):`, `fix:`.
- **Não criar PR sem o usuário pedir.** Integração é por PR + review.
- **Não** comitar segredos, arquivos temporários, ou `node_modules`.

## Não-objetivos (evite)

- Nada de **pay-to-win** no design de monetização ([docs/12](docs/12-BUSINESS-PLAN.md)).
- Não transformar os protótipos em apps com build/toolchain pesado — manter abríveis com 1 clique.
- Não prometer "o jogo AAA pronto": o build final em UE5.6 é a produção de ~6 anos do [docs/11](docs/11-PRODUCTION-PLAN.md). Entregar **camada por camada**, com honestidade de escopo.

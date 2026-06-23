# Contribuindo com o MOGUL (Project ATLAS)

Este projeto é desenvolvido de forma colaborativa por **pessoas e instâncias do Claude**, usando o
**GitHub como ponto de integração**. Não existe "sessão compartilhada ao vivo" entre contas do
Claude — cada pessoa usa a própria conta e a colaboração acontece via **branches + Pull Requests**.

## Como entrar no projeto (passo a passo para um novo colaborador)

1. **Tenha uma conta com Claude Code on the web** — em *research preview* para planos **Pro, Max,
   Team** e **Enterprise** (premium / Chat + Claude Code seats). Ref: docs oficiais (link abaixo).
2. **Ganhe acesso ao repositório** `Ramonandreee/Game`:
   - O dono adiciona você em **GitHub → repo → Settings → Collaborators → Add people**; ou
   - O repo é movido para uma **organização/equipe** e você entra no time.
   - *Uma sessão na nuvem enxerga qualquer repo que a sua conta GitHub conectada consiga ver.*
3. **Conecte o GitHub à sua conta Claude**:
   - **GitHub App** durante o onboarding em `claude.ai/code`, **ou**
   - rode **`/web-setup`** no terminal (sincroniza seu token do `gh`).
4. **Abra uma sessão** em `claude.ai/code`, selecione o repositório `Ramonandreee/Game` e comece.
5. **Trabalhe numa branch própria** (nunca na default) e abra um **Pull Request** quando pronto.

> 📖 Documentação oficial: <https://code.claude.com/docs/en/claude-code-on-the-web>
> (seções *GitHub authentication options* e *Work with sessions › Share sessions*).

## Compartilhar uma sessão (opcional, read-only)

Você pode compartilhar o **link de uma sessão** para alguém ver o que ela fez — mas é um
**snapshot, não tempo real** (a visão do destinatário não atualiza sozinha). Em conta **Team**,
use visibilidade *Team*; em **Max/Pro**, cuidado com *Public* (a sessão pode conter código/credenciais
do repo privado). Co-desenvolvimento real continua sendo via PRs.

## Fluxo de trabalho

| Passo | Convenção |
|------|-----------|
| **Branch** | `feature/<assunto>`, `fix/<assunto>` ou `claude/<assunto>`. Uma branch por tarefa. |
| **Commits** | Descritivos (PT-BR ok). Prefixos: `docs:`, `feat(game):`, `feat(world):`, `fix:`, `chore:`. |
| **Validação** | Mudou protótipo? Rode os checks (ver abaixo) **antes** do push. |
| **PR** | Use o template. Descreva o que muda, qual pilar serve, e o que foi validado. |
| **Review** | Pelo menos uma revisão antes do merge. Resolva comentários por commits na mesma branch. |
| **Merge** | Squash & merge na default branch. Apague a branch depois. |

> ⚠️ **Não crie PRs automaticamente** sem o dono pedir. Não faça push direto na default branch.

## Validação local (resumo — detalhes em [CLAUDE.md](CLAUDE.md))

Para mudanças em `game/` ou `world/`:

1. **Sintaxe** — `node --check` no script extraído (`.mjs` para o mundo 3D).
2. **Economia headless** — rodar centenas de dias simulados: sem exceções, progride pelas 5 fases, falência possível mas não garantida.
3. **UI smoke test** — stub de DOM exercitando render/modais/eventos sem lançar.

Use o diretório scratchpad da sua sessão para harnesses temporários — **não comite** arquivos de teste.

## Estrutura & princípios

Antes de mexer, leia [CLAUDE.md](CLAUDE.md) (princípios de design, Pillar Gate, convenções) e os
[fatos canônicos no README](README.md). Toda feature passa pelo **Pillar Gate**:
*"isso faz o jogador sentir que está construindo um império?"*.

## Dúvidas

Abra uma *issue* no GitHub descrevendo a proposta antes de um trabalho grande, para alinhar com a visão.

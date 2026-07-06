# MOGUL — Scaffold do projeto Unreal Engine 5.6

> O **ponto de partida de engine** descrito no [doc 10](../docs/10-TECHNICAL-ARCHITECTURE.md). Não é o jogo pronto — é o **esqueleto real, abrível no editor**, com a arquitetura do GDD e a economia já validada portada para C++.

## ⚠️ Leia primeiro (honestidade de escopo)

Isto é um **scaffold de pré-produção**, não o build AAA final. Ele estabelece a **espinha arquitetural** (módulo, subsistemas, tipos de dados, save) para um time de engenharia começar a preencher. O mundo aberto navegável, MetaHumans, Nanite/Lumen art, diálogo por LLM e Mass crowds são o trabalho de produção do [doc 11](../docs/11-PRODUCTION-PLAN.md) (~6 anos). Para *jogar agora*, use os protótipos em [`../game`](../game) (2D) e [`../world`](../world) (3D no navegador).

> Como não há Unreal Engine neste ambiente, **este C++ não foi compilado aqui**. Foi escrito nas convenções da UE5.6 e pode exigir pequenos ajustes ao abrir (ex.: nomes exatos de módulos Mass conforme a sua instalação, e o plugin MetaHuman — ver abaixo).

## Como abrir

1. Instale o **Unreal Engine 5.6** (Epic Games Launcher).
2. Clique com o botão direito em `MOGUL.uproject` → **Generate Visual Studio project files** (ou use o Rider).
3. Abra `MOGUL.uproject`. Se pedir para compilar os módulos, aceite (**Yes**).
4. (Opcional) Habilite o plugin **MetaHuman** via Fab/Bridge — deixei-o **fora** do `.uproject` de propósito para o projeto abrir sem erro de plugin ausente. Adicione quando for trabalhar personagens.

## Arquitetura (mapa para o doc 10)

```
Source/MOGUL/
  World/
    MogulCityBootstrap        Rig de mundo: sol/céu/nuvens/fog físicos + post AAA
                              + cidade greybox por distrito (seed) — doc 13
  Core/
    MogulGameInstance         Lifetime dos subsistemas globais
    MogulGameModeBase         Game mode base (auto-spawna o rig em levels sem céu)
    MogulSimulationSubsystem  "World tick" (FTickableGameObject) — doc 10 §3
    MogulEventBus             Event-Driven Architecture — doc 10 §3.2
  Economy/
    MogulEconomyTypes.h       FMogulCompany, FMogulMarket, FMogulEmployeeRef…
    MogulNicheDataAsset       Setores data-driven (designers, sem código) — doc 06 §3
    MogulEconomySubsystem     "Economy Engine" — doc 10 §4 (FÓRMULAS VALIDADAS)
  Agents/
    MogulAgentTypes.h         Big Five, memória, tiers — doc 07
    MogulAgentSubsystem       Registro/geração/memória de agentes Tier 2/3 — doc 07 §2
  Save/
    MogulSaveGame             Snapshot versionado — doc 10 §7
    MogulSaveSubsystem        Save/Load + migração de schema
```

| Subsistema | Tipo | Papel |
|-----------|------|-------|
| `UMogulEconomySubsystem` | GameInstanceSubsystem | Macro/empresas/mercado; **mesma economia balanceada dos protótipos** |
| `UMogulAgentSubsystem` | GameInstanceSubsystem | Agentes persistentes (perfil, Big Five, memória, LOD de cognição) |
| `UMogulSimulationSubsystem` | GameInstanceSubsystem + FTickableGameObject | Avança o mundo (dias), dispara eventos |
| `UMogulEventBus` | GameInstanceSubsystem | EDA: `Emit("DayAdvanced", …)`, qualquer sistema assina |
| `UMogulSaveSubsystem` | GameInstanceSubsystem | Persistência versionada |

## O detalhe que importa: a economia já é a validada

`MogulEconomySubsystem.cpp` é um **port fiel** do modelo provado por simulação headless nos protótipos (mesmas fórmulas de receita/custo/valuation, mesmos ciclos de mercado, mesmos limiares das 5 fases). Ou seja, o scaffold **não começa do zero** — já traz o coração econômico afinado. Teste rápido em C++:

```cpp
if (UMogulEconomySubsystem* Econ = GetGameInstance()->GetSubsystem<UMogulEconomySubsystem>())
{
    Econ->FoundCompany(TEXT("saas"), TEXT("Vertex Labs"));
    for (int i = 0; i < 100; ++i) { Econ->TickEconomyDay(); }
    UE_LOG(LogMogul, Log, TEXT("Net worth: %.0f, phase %d"), Econ->GetNetWorth(), Econ->PhaseLevel);
}
```

## Plugins habilitados (`MOGUL.uproject`)
EnhancedInput, GameplayAbilities (GAS), PCG, MassEntity/MassGameplay/MassAI, StateTree/GameplayStateTree, SmartObjects, ChaosVehicles, Water, ModelingToolsEditorMode. Nanite e Lumen são ligados em `Config/DefaultEngine.ini` (features de engine, não plugins).

## 🌇 A Cena Meridian — onde o fotorrealismo começa

O `AMogulCityBootstrap` (em `Source/MOGUL/World/`) transforma **qualquer level** no ponto
de partida fotorrealista do [doc 13](../docs/13-ART-DIRECTION.md):

- **Iluminação física**: sol direcional em *golden hour* (50.000 lux, disco suave),
  **SkyAtmosphere** (céu físico), **nuvens volumétricas**, **fog volumétrico**,
  **SkyLight em captura em tempo real** (o GI do céu acompanha o sol) — tudo sob **Lumen**
- **Post-process AAA contido**: exposição automática por histograma (+0.3 EV),
  **bloom 0.20** (calibrado no protótipo), motion blur 0.35, vinheta, grão de filme sutil
- **Cidade greybox por distrito**: a MESMA massa urbana de Meridian do protótipo
  (Sterling com torres + pódios, Grid, Boroughs, Ironside, Goldhaven), gerada por
  `RandomSeed` determinístico via InstancedStaticMesh — edite o seed no editor e a
  cidade regenera na hora

**Como ver:** abra o projeto → compile → **File > New Level > Empty Level** → Play.
O GameMode detecta que o level não tem céu e spawna o rig sozinho (em maps de template,
que já têm sol, ele **não** duplica a luz — coloque o ator manualmente se quiser forçar).
Voe com o DefaultPawn (WASD + mouse) pela massa urbana sob a luz de fim de tarde.

**De greybox a fotorrealismo** (o caminho de produção, doc 13 §4):
1. Substituir os cubos por kits de fachada com **Nanite** (Fab/Quixel Megascans — gratuito p/ UE)
2. Materiais **PBR completos** (albedo/normal/roughness/metallic/AO) nos kits
3. **MetaHumans** para a população; **PCG** para espalhar detalhe urbano
4. O rig de luz/post permanece — é ele que faz até o greybox "parecer foto"

## Próximos passos de engine (roadmap do doc 11)
1. **Player Character** + EnhancedInput (a navegação 1ª pessoa prototipada em `../world`).
2. **Mass crowds** (Tier 0/1) povoando o World Partition de Meridian.
3. **DataAssets de setor** em `Content/Data/Niches/` (wire o `LoadNichesFromAssets`).
4. **StateTree/GOAP** para decisão de agentes Tier 2; integração LLM (Tier 3) via gateway (doc 10 §5).
5. **PCG** para os quarteirões; **MetaHuman** para a população.

*Este scaffold é o "Mês 1" do doc 11 — a fundação sobre a qual a produção é construída.*

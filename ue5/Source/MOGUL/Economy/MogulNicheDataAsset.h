// MOGUL (Project ATLAS) — data-driven niche definition.
// Designers create one asset per niche under Content/Data/Niches/ (no code change
// to add sectors — see docs/06-BUSINESS-SYSTEMS.md §3 and docs/10 "data-driven").
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Economy/MogulEconomyTypes.h"
#include "MogulNicheDataAsset.generated.h"

UCLASS(BlueprintType)
class MOGUL_API UMogulNicheDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Niche")
	FName NicheId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Niche")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Niche", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Niche|Tuning")
	FMogulNicheParams Params;

	// Convenience: pack the editable fields into a runtime params struct.
	FMogulNicheParams ToParams() const
	{
		FMogulNicheParams P = Params;
		P.NicheId = NicheId;
		return P;
	}

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(TEXT("MogulNiche"), NicheId);
	}
};

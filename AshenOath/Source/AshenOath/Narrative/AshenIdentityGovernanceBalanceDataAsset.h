// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Narrative/AshenIdentityCompilerTypes.h"
#include "AshenIdentityGovernanceBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FIdentityGovernanceLimits
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Governance Limits", meta = (ClampMin = "0.05", ClampMax = "0.50"))
	float MaxAllowableDelta = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Governance Limits", meta = (ClampMin = "1", ClampMax = "16"))
	int32 MaxJsonPayloadSizeKB = 4;
};

USTRUCT(BlueprintType)
struct FMemoryDecayBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory Decay", meta = (ClampMin = "0.001", ClampMax = "0.10"))
	float TraumaDecayLambda = 0.02f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory Decay", meta = (ClampMin = "0.01", ClampMax = "0.25"))
	float BondDecayLambda = 0.08f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory Decay", meta = (ClampMin = "0.005", ClampMax = "0.15"))
	float EpiphanyDecayLambda = 0.03f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory Decay", meta = (ClampMin = "0.02", ClampMax = "0.35"))
	float CombatTitheDecayLambda = 0.12f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory Decay", meta = (ClampMin = "0.05", ClampMax = "0.50"))
	float ActiveSalienceThreshold = 0.15f;
};

/**
 * UAshenIdentityGovernanceBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for the Reflective Identity Compiler & SLM Governance Layer (RIC-003).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenIdentityGovernanceBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Governance Limits")
	FIdentityGovernanceLimits GovernanceLimits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Memory Decay")
	FMemoryDecayBalancing DecayBalancing;

	FIdentityGovernanceLimits GetClampedLimits() const;
	FMemoryDecayBalancing GetClampedDecay() const;
	float GetLambdaForCategory(EImprintSalienceCategory Category) const;
};

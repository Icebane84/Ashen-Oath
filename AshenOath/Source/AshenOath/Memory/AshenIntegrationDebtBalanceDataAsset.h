// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenIntegrationDebtBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FIntegrationDebtStageThresholds
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.10", ClampMax = "0.70"))
	float MemoryBleedThreshold = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.50", ClampMax = "0.95"))
	float RuntimeNoiseThreshold = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.80", ClampMax = "1.00"))
	float ForcedCollapseThreshold = 1.00f;
};

USTRUCT(BlueprintType)
struct FIntegrationDebtPenalties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.05", ClampMax = "0.30"))
	float DefaultParryWindowSeconds = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.02", ClampMax = "0.20"))
	float DegradedParryWindowSeconds = 0.12f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.05", ClampMax = "0.60"))
	float StaminaRecoveryHandicap = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float MemoryBleedDesaturation = 0.40f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debt Balancing", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float RuntimeNoiseDesaturation = 0.75f;
};

/**
 * UAshenIntegrationDebtBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for the Integration Debt & Memory Bleed pipeline.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenIntegrationDebtBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Integration Debt | Thresholds")
	FIntegrationDebtStageThresholds StageThresholds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Integration Debt | Penalties")
	FIntegrationDebtPenalties Penalties;

	FIntegrationDebtStageThresholds GetClampedThresholds() const;
	FIntegrationDebtPenalties GetClampedPenalties() const;
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AshenRunicForgeBalanceDataAsset.generated.h"

/**
 * UAshenRunicForgeBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for the Runic Forge & Flow Glint Proximity Matrix (AOP-MASTER-CONVERGENCE-SPEC-V2.0).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenRunicForgeBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Flow Glint Timing", meta = (ClampMin = "0.05", ClampMax = "0.30"))
	float FlowGlintWindowSeconds = 0.15f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spatial Invariants", meta = (ClampMin = "100.0", ClampMax = "400.0"))
	float FlowGlintMaxProximityRadius = 200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spatial Invariants", meta = (ClampMin = "400.0", ClampMax = "1000.0"))
	float IsolatedCompanionRetractionBuffer = 650.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Kinetic Stance Radii", meta = (ClampMin = "300.0", ClampMax = "1200.0"))
	float VomTagColossusShockwaveRadius = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Kinetic Stance Radii", meta = (ClampMin = "400.0", ClampMax = "1500.0"))
	float PflugZephyrVacuumRadius = 800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ascension Thresholds", meta = (ClampMin = "0.10", ClampMax = "0.50"))
	float Tier2DebtThreshold = 0.25f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ascension Thresholds", meta = (ClampMin = "0.50", ClampMax = "0.90"))
	float Tier3TrioResonanceThreshold = 0.65f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ascension Thresholds", meta = (ClampMin = "0.40", ClampMax = "0.80"))
	float Tier4CorruptionThreshold = 0.50f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ascension Thresholds", meta = (ClampMin = "0.50", ClampMax = "0.90"))
	float Tier4ResolveThreshold = 0.70f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ascension Thresholds", meta = (ClampMin = "0.80", ClampMax = "1.00"))
	float Tier5ResolveThreshold = 0.90f;
};

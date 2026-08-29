// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AshenBladeSanityBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FBladeHungerCombatBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blade Balancing", meta = (ClampMin = "1.0", ClampMax = "2.5"))
	float MaxDamageMultiplier = 1.45f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blade Balancing", meta = (ClampMin = "0.05", ClampMax = "0.60"))
	float MaxParryWindowPenalty = 0.35f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blade Balancing", meta = (ClampMin = "1.0", ClampMax = "3.0"))
	float MaxDodgeStaminaMultiplier = 1.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blade Balancing", meta = (ClampMin = "0.1", ClampMax = "5.0"))
	float HungerSanityDrainRatePerSecond = 1.50f;
};

USTRUCT(BlueprintType)
struct FFlowCatharsisBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flow Balancing", meta = (ClampMin = "10.0", ClampMax = "100.0"))
	float InstantSanityHeal = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flow Balancing", meta = (ClampMin = "3.0", ClampMax = "20.0"))
	float FlowDurationSeconds = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flow Balancing", meta = (ClampMin = "1.0", ClampMax = "4.0"))
	float FlowStaminaRegenMultiplier = 2.0f;
};

USTRUCT(BlueprintType)
struct FQuartzConductorBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Balancing", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float MaxStem02WhisperGain = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Balancing", meta = (ClampMin = "-36.0", ClampMax = "0.0"))
	float MaxMelodicDuckingDb = -18.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Balancing", meta = (ClampMin = "100.0", ClampMax = "12000.0"))
	float MinLPFCutoffHz = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Balancing", meta = (ClampMin = "4000.0", ClampMax = "22000.0"))
	float MaxLPFCutoffHz = 8000.0f;
};

/**
 * UAshenBladeSanityBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for the Parasitic Blade Hunger & Flow Catharsis Loop (CONVERGENCE-SPEC-090).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenBladeSanityBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Blade Hunger")
	FBladeHungerCombatBalancing BladeHungerParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Flow Catharsis")
	FFlowCatharsisBalancing FlowCatharsisParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Quartz Conductor")
	FQuartzConductorBalancing QuartzConductorParams;

	FBladeHungerCombatBalancing GetClampedBladeHunger() const;
	FFlowCatharsisBalancing GetClampedFlowCatharsis() const;
	FQuartzConductorBalancing GetClampedQuartzConductor() const;
};

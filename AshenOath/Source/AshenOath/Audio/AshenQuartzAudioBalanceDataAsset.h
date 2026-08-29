// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenQuartzAudioBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FQuartzClockBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quartz Clock", meta = (ClampMin = "60.0", ClampMax = "200.0"))
	float BeatsPerMinute = 115.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quartz Clock", meta = (ClampMin = "2.0", ClampMax = "16.0"))
	float FlowStateDurationSeconds = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quartz Clock", meta = (ClampMin = "1.0", ClampMax = "4.0"))
	float FlowStaminaRegenMultiplier = 2.0f;
};

USTRUCT(BlueprintType)
struct FAlchemicalFilterBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemical Audio", meta = (ClampMin = "100.0", ClampMax = "2000.0"))
	float SmokeLowPassCutoffHz = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemical Audio", meta = (ClampMin = "-48.0", ClampMax = "0.0"))
	float TackleSideChainDuckingDB = -24.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemical Audio", meta = (ClampMin = "-24.0", ClampMax = "0.0"))
	float GloomwoodPitchOffsetSemitones = -12.0f;
};

/**
 * UAshenQuartzAudioBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for the 6-Stem Quartz Conductor & Alchemical Filters (QUARTZ-SPEC-084).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenQuartzAudioBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Clock & Flow")
	FQuartzClockBalancing ClockBalancing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Alchemical Filters")
	FAlchemicalFilterBalancing FilterBalancing;

	FQuartzClockBalancing GetClampedClockBalancing() const;
	FAlchemicalFilterBalancing GetClampedFilterBalancing() const;
};

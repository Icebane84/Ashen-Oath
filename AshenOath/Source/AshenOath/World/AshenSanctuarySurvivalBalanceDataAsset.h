// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuarySurvivalBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FShelterThermodynamicBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shelter Balancing", meta = (ClampMin = "-10.0", ClampMax = "0.0"))
	float WildernessHypothermiaHPLoss = -2.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shelter Balancing", meta = (ClampMin = "1.0", ClampMax = "5.0"))
	float CavernCookingSpeedMultiplier = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shelter Balancing", meta = (ClampMin = "0.0", ClampMax = "20.0"))
	float HearthHealthRegenPerSecond = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shelter Balancing", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float CavernWindbreakReduction = 0.75f;
};

USTRUCT(BlueprintType)
struct FSurvivalMealBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meal Balancing", meta = (ClampMin = "60.0", ClampMax = "3600.0"))
	float DefaultMealDurationSeconds = 900.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meal Balancing", meta = (ClampMin = "0.50", ClampMax = "1.00"))
	float MatchedHazardDamageReduction = 1.00f; // 100% immunity
};

USTRUCT(BlueprintType)
struct FSanctuaryBeaconBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beacon Balancing", meta = (ClampMin = "300.0", ClampMax = "5000.0"))
	float BeaconHavenRadiusUU = 1200.0f;
};

/**
 * UAshenSanctuarySurvivalBalanceDataAsset
 * Primary DataAsset exposing live editor tuning parameters for the Sanctuary & Survival Ecosystem (SANCTUARY-SURVIVAL-SPEC-096).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSanctuarySurvivalBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Shelter")
	FShelterThermodynamicBalancing ShelterBalancing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Meals")
	FSurvivalMealBalancing MealBalancing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence | Beacons")
	FSanctuaryBeaconBalancing BeaconBalancing;

	FShelterThermodynamicBalancing GetClampedShelterBalancing() const;
	FSurvivalMealBalancing GetClampedMealBalancing() const;
	FSanctuaryBeaconBalancing GetClampedBeaconBalancing() const;
};

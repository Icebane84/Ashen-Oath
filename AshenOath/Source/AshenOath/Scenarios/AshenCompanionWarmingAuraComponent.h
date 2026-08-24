// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenCompanionWarmingAuraComponent.generated.h"

/**
 * UAshenCompanionWarmingAuraComponent
 * 
 * Emits a thermal warming zone around Garrett (Kindle Torch) or Serafina (White Flame Aura).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionWarmingAuraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionWarmingAuraComponent();

	/** Checks if target location is within thermal warming radius */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6|Warmth")
	bool IsActorWithinWarmthRadius(const FVector& SourceLocation, const FVector& TargetLocation) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6|Warmth")
	float WarmingRadiusUU = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6|Warmth")
	float ThermalHeatOutputCelsius = 25.0f;
};

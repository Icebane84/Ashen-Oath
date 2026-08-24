// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenMagmaSurgeHazardDirectorComponent.generated.h"

/**
 * UAshenMagmaSurgeHazardDirectorComponent
 * 
 * Coordinates 15-second volcanic magma eruption cycles: Dormant (10s), Telegraph (3s), Eruption (2s).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMagmaSurgeHazardDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMagmaSurgeHazardDirectorComponent();

	/** Evaluates current eruption phase from cycle elapsed time */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|Magma")
	ECalderaSurgePhase EvaluateSurgePhaseFromTime(float ElapsedSeconds) const;
};

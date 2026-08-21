// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenSomaticFrictionHapticBridge.generated.h"

/**
 * UAshenSomaticFrictionHapticBridge
 * 
 * Maps psychological somatic friction and weapon mass into continuous trigger feedback configurations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticFrictionHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticFrictionHapticBridge();

	/** Builds a continuous feedback trigger config from weapon mass and dysregulation */
	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	FDualSenseTriggerConfig BuildSomaticTriggerConfig(
		float EffectiveMassKg,
		float DysregulationScalar) const;
};

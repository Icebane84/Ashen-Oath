// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTacticalHapticBridge.generated.h"

/**
 * UAshenTacticalHapticBridge
 * 
 * Translates tactical wheel sector hovering into micro-tactile clicks and trigger detents.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalHapticBridge();

	/** Evaluates haptic tick intensity for sector boundary crossings */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tactics|Haptics")
	float EvaluateSectorTickIntensity(int32 OldSector, int32 NewSector) const;
};

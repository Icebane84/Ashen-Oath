// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexHapticBridge.generated.h"

/**
 * UAshenCodexHapticBridge
 * 
 * Maps parchment page turns and 3D relic inspection rotation detents to DualSense haptic rumble.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCodexHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCodexHapticBridge();

	/** Evaluates haptic rumble feedback during relic examination */
	UFUNCTION(BlueprintPure, Category = "Ashen|Archive|Haptics")
	float EvaluateInspectionHapticIntensity(bool bSecretRevealed, float DecodedPercent) const;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenScenario2HapticBridge.generated.h"

/**
 * UAshenScenario2HapticBridge
 * 
 * Maps dual-channel DualSense haptics: Left-channel Corruption rumble vs Right-channel White Flame spark.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario2HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario2HapticBridge();

	/** Evaluates Left-channel rumble (Corruption) and Right-channel spark (White Flame) */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2|Haptics")
	void EvaluateDualChannelHaptics(
		float CorruptionLevel,
		bool bPhosphorFlareActive,
		float& OutLeftRumble,
		float& OutRightSpark) const;
};

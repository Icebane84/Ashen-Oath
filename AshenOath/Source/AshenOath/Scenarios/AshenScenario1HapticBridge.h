// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenScenario1HapticBridge.generated.h"

/**
 * UAshenScenario1HapticBridge
 * 
 * Maps Titan's Stand trigger resistance (0–100 scale) and auditory isolation haptic rumble.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario1HapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario1HapticBridge();

	/** Evaluates DualSense trigger resistance for Titan's Stand parry */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1|Haptics")
	float EvaluateTitansStandTriggerResistance(bool bIsParrying, EMalakorBossPhase Phase) const;
};

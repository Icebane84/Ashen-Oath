// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenCampfireAudioSubsystem.generated.h"

/**
 * UAshenCampfireAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing bubbling stew boiling loops, wooden spoon stirring clinks, and soul-ember crackles.
 */
UCLASS()
class ASHENOATH_API UAshenCampfireAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCampfireAudioSubsystem();

	/** Evaluates boiling bubble loop gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Campfire")
	float EvaluateBoilingBubbleGain(float TemperatureCelsius) const;

	/** Evaluates fire ember crackle volume [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Campfire")
	float EvaluateEmberCrackleVolume(ECookingPotState PotState) const;
};

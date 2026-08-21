// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenOakhavenAudioSubsystem.generated.h"

/**
 * UAshenOakhavenAudioSubsystem
 * 
 * Synthesizes amber flame audio, masonry creaking under null zone cascades, and controller whispers.
 */
UCLASS()
class ASHENOATH_API UAshenOakhavenAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenOakhavenAudioSubsystem();

	/** Evaluates the low-pass audio cutoff frequency during Null Zone cascade */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario1")
	float EvaluateNullZoneCutoffHz(bool bNullZoneActive) const;

	/** Evaluates the volume of Shadow Self whispers based on accumulated debt */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario1")
	float EvaluateShadowWhisperVolume(float IntegrationDebt) const;
};

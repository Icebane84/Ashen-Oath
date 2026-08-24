// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenOathbringerAudioSubsystem.generated.h"

/**
 * UAshenOathbringerAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing Oathbringer's nightsteel groan, 12-semitone pitch drops, and controller speaker whispers (300Hz-2400Hz).
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenOathbringerAudioSubsystem();

	/** Evaluates nightsteel discordant hum volume [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Blade")
	float EvaluateNightsteelHumGain(float Corruption01, bool bIsFrozen) const;

	/** Evaluates audio pitch offset for chemical cooling [-12.0 semitones] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Blade")
	float EvaluateBloodChillPitchSemitones(bool bIsFrozen) const;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenEldrinDialogueBridge.generated.h"

/**
 * UAshenEldrinDialogueBridge
 * 
 * Generates contextual internal dialogue lines from Eldrin's imprisoned spirit and Nyx's parasite.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEldrinDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEldrinDialogueBridge();

	/** Formats whisper text based on corruption level and target */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Blade")
	FText FormatEldrinWhisper(float Corruption01, EPommelGazeTarget GazeTarget) const;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenWaystationDialogueBridge.generated.h"

/**
 * UAshenWaystationDialogueBridge
 * 
 * Injects Garrett's dual-wield tactical barks and Serafina's reactions based on the active run mode.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWaystationDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWaystationDialogueBridge();

	/** Formats dialogue based on the active run mode */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Waystation")
	FText FormatRunBark(EWaystationRunMode Mode) const;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenWaystationMasterBridge.generated.h"

/**
 * UAshenWaystationMasterBridge
 * 
 * Master orchestrator connecting the 4-run crucible, dialogue, haptics, and campfire forensic journal.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWaystationMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWaystationMasterBridge();

	/** Broadcasts completion of the 7-minute vertical slice vignette */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Waystation")
	void BroadcastVignetteCompleted(EWaystationRunMode RunMode, bool bZeroDowned);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Waystation")
	FOnCrucibleCombatCompleted OnVignetteFinished;
};

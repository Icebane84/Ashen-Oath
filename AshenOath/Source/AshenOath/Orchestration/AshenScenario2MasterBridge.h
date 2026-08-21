// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenScenario2MasterBridge.generated.h"

/**
 * UAshenScenario2MasterBridge
 * 
 * Master orchestrator connecting Scenario 2 trap systems, AI circuit breakers, dialogue, and HUD.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario2MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario2MasterBridge();

	/** Broadcasts mission conclusion */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario2")
	void BroadcastGambitCompleted(bool bSilentEscape);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario2")
	FOnSentinelsGambitCompleted OnSentinelsGambitCompleted;
};

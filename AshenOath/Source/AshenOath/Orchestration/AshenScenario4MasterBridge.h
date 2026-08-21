// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenScenario4MasterBridge.generated.h"

/**
 * UAshenScenario4MasterBridge
 * 
 * Master orchestrator connecting Scenario 4 Companion Grounding, Sanity distortion, dialogue, and HUD.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario4MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario4MasterBridge();

	/** Broadcasts completion of Whisperwood crossing */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario4")
	void BroadcastWhisperwoodCleared(bool bSanityMaintained);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario4")
	FOnWhisperwoodCleared OnWhisperwoodCleared;
};

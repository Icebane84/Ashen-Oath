// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenScenario5MasterBridge.generated.h"

/**
 * UAshenScenario5MasterBridge
 * 
 * Master orchestrator connecting Scenario 5 Unchained combat, mire hazards, audio, and SaveGame.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario5MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario5MasterBridge();

	/** Broadcasts completion of Weeping Mire skirmish */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario5")
	void BroadcastWeepingMireCleared(bool bZeroCompanionDowned);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario5")
	FOnWeepingMireCleared OnWeepingMireCleared;
};

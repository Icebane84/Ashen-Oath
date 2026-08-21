// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenScenario1MasterBridge.generated.h"

/**
 * UAshenScenario1MasterBridge
 * 
 * Master orchestrator connecting Scenario 1 boss state, ritual altar, dialogue, audio whispers, and UI.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario1MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario1MasterBridge();

	/** Broadcasts mission conclusion */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario1")
	void BroadcastChapelCleared(bool bRitualSuccessful);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario1")
	FOnOakhavenChapelCleared OnOakhavenChapelCleared;
};

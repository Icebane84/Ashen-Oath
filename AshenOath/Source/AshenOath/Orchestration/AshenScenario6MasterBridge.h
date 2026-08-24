// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenScenario6MasterBridge.generated.h"

/**
 * UAshenScenario6MasterBridge
 * 
 * Master orchestrator connecting blizzard thermodynamics, AI huddling, DualSense haptics, and hearth ignition.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario6MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario6MasterBridge();

	/** Broadcasts a Scenario 6 state update event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario6")
	void BroadcastScenario6Update(float Frostbite, float HearthIgnition, bool bInWarmth);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario6")
	FOnFrostbiteUpdated OnFrostbiteBroadcaster;
};

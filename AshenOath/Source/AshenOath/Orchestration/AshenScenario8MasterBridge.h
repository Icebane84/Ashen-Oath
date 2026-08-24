// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenScenario8MasterBridge.generated.h"

/**
 * UAshenScenario8MasterBridge
 * 
 * Master orchestrator connecting torch endurance, echolocation sonar, darkness debuffs, audio, and narrative barks.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario8MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario8MasterBridge();

	/** Broadcasts a torch fuel and illumination update */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario8")
	void BroadcastTorchUpdate(float Fuel01, float LightRadiusUU);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario8")
	FOnTorchFuelChanged OnTorchBroadcaster;
};

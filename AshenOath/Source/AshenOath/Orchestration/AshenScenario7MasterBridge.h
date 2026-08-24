// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenScenario7MasterBridge.generated.h"

/**
 * UAshenScenario7MasterBridge
 * 
 * Master orchestrator connecting caldera thermodynamics, companion cooling mist, magma hazards, and blade tempering.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario7MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario7MasterBridge();

	/** Broadcasts a caldera thermodynamic update */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario7")
	void BroadcastCalderaUpdate(float TempC, float HeatExhaustion);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario7")
	FOnCalderaTemperatureChanged OnCalderaBroadcaster;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenScenario9MasterBridge.generated.h"

/**
 * UAshenScenario9MasterBridge
 * 
 * Master orchestrator connecting void gravity fields, wind shear physics, telekinetic bridges, and dialogue.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario9MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario9MasterBridge();

	/** Broadcasts a gravity and wind update */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario9")
	void BroadcastCitadelUpdate(EVoidGravityZoneTier Tier, float GravityScale);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario9")
	FOnGravityZoneChanged OnGravityBroadcaster;
};

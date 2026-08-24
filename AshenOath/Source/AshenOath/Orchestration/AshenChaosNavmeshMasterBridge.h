// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosNavmeshMasterBridge.generated.h"

/**
 * UAshenChaosNavmeshMasterBridge
 * 
 * Master orchestrator unifying Chaos geometry fracture events with dynamic navmesh regeneration, audio, and haptics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosNavmeshMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosNavmeshMasterBridge();

	/** Broadcasts a structural demolition and navmesh cutting event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Chaos")
	void BroadcastDemolitionEvent(const FVector& Location, ENavmeshObstructionState Obstruction);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Chaos")
	FOnNavmeshObstructionChanged OnObstructionBroadcaster;
};

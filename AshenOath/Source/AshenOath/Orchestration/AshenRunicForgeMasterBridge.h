// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenRunicForgeMasterBridge.generated.h"

/**
 * UAshenRunicForgeMasterBridge
 * 
 * Master orchestrator connecting campfire anvil interactions, weapon ascension state, 4 guard sigils, and HUD.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicForgeMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicForgeMasterBridge();

	/** Broadcasts live blade ascension update across game modules */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|RunicForge")
	void BroadcastAscensionUpdate(EOathbringerAscensionTier Tier, const FOathbringerEvolutionState& State);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|RunicForge")
	FOnOathbringerTierAscended OnAscensionBroadcaster;
};

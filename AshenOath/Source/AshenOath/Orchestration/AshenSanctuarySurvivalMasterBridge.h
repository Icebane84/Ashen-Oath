// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuarySurvivalMasterBridge.generated.h"

/**
 * UAshenSanctuarySurvivalMasterBridge
 * 
 * Master orchestrator connecting campfire cooking buffs, weather exposure, shelter tiers, beacon activations, and HUD.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuarySurvivalMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuarySurvivalMasterBridge();

	/** Broadcasts live shelter tier update across game modules */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Survival")
	void BroadcastShelterUpdate(EThermalShelterTier Tier, const FShelterThermodynamicState& State);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Survival")
	FOnShelterTierChanged OnShelterBroadcaster;
};

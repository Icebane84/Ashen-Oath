// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenCampfireCookingMasterBridge.generated.h"

/**
 * UAshenCampfireCookingMasterBridge
 * 
 * Master orchestrator connecting campfire cooking cauldron subsystems, GAS meal buffs, UMG UI recipe interfaces, and companion audio.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireCookingMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireCookingMasterBridge();

	/** Broadcasts live cooking pot telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Cooking")
	void BroadcastCookingState(const FCampfireStewStateVector& State);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Cooking")
	FOnCookingStateChanged OnCookingBroadcaster;
};

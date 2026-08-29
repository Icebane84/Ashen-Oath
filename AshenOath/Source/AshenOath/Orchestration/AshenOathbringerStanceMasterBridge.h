// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerStanceMasterBridge.generated.h"

/**
 * UAshenOathbringerStanceMasterBridge
 * 
 * Master orchestrator connecting the Oathbringer stance flow subsystem, GAS stance abilities, HUD diamond visualizer, and haptics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerStanceMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerStanceMasterBridge();

	/** Broadcasts live stance state update across listener domains */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Stance")
	void BroadcastStanceUpdate(EOathbringerMartialStance Stance, const FOathbringerStanceKinematics& Kinematics);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Stance")
	FOnOathbringerStanceChanged OnStanceBroadcaster;
};

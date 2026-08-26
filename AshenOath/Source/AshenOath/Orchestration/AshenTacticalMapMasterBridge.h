// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTacticalMapMasterBridge.generated.h"

/**
 * UAshenTacticalMapMasterBridge
 * 
 * Master orchestrator bridging the tactical cartography subsystem, GAS fast travel abilities, UMG map widgets, and audio feedback.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalMapMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalMapMasterBridge();

	/** Broadcasts live waypoint state change */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Map")
	void BroadcastWaypointState(const FString& WaypointId, EWaypointBeaconState NewState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Map")
	FOnWaypointStateChanged OnWaypointBroadcaster;
};

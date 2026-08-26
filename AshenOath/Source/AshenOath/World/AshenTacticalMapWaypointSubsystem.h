// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTacticalMapWaypointSubsystem.generated.h"

/**
 * UAshenTacticalMapWaypointSubsystem
 * 
 * Central world subsystem managing cartographic waypoints, beacon attunement, and overland fast travel.
 */
UCLASS()
class ASHENOATH_API UAshenTacticalMapWaypointSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenTacticalMapWaypointSubsystem();

	/** Attunes a discovered waypoint beacon */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Map")
	bool AttuneWaypoint(const FString& WaypointId);

	/** Initiates fast travel from active waypoint to destination */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Map")
	bool ExecuteFastTravel(const FString& DestinationWaypointId);

	/** Unveils a section of the fog of war */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Map")
	void UnveilFogAtLocation(const FVector& Location, float RadiusUU);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Map")
	FOnWaypointStateChanged OnWaypointStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Map")
	FOnFastTravelInitiated OnFastTravelInitiated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Map")
	FOnTravelHazardTriggered OnTravelHazardTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Map")
	FOnFogOfWarUnveiled OnFogOfWarUnveiled;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Map")
	TArray<FTacticalWaypointVector> RegisteredWaypoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Map")
	FString CurrentSanctuaryId = TEXT("Waypoint_Hearth_01");
};

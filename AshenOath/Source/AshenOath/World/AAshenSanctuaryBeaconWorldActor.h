// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/AshenTacticalMapTypes.h"
#include "AAshenSanctuaryBeaconWorldActor.generated.h"

/**
 * AAshenSanctuaryBeaconWorldActor
 * 
 * Spatial world actor representing the stone campfire sanctuary brazier, interactive attunement trigger, and fast travel landing zone.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryBeaconWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryBeaconWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Map")
	FString GetBeaconId() const { return BeaconId; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Map")
	EWaypointBeaconState GetBeaconState() const { return BeaconState; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	FString BeaconId = TEXT("Waypoint_Hearth_01");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	EWaypointBeaconState BeaconState = EWaypointBeaconState::UndiscoveredShadow;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AAshenFloatingArchipelagoIslandActor.generated.h"

class UBoxComponent;

/**
 * AAshenFloatingArchipelagoIslandActor
 * 
 * Spatial world actor in Scenario 9 representing hovering citadel islands with low-gravity zones and anchor tether sockets.
 */
UCLASS()
class ASHENOATH_API AAshenFloatingArchipelagoIslandActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenFloatingArchipelagoIslandActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|World")
	float GetIslandAltitudeUU() const { return IslandAltitudeUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* IslandBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9")
	float IslandAltitudeUU = 8500.0f;
};

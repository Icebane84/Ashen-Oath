// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AAshenMagmaVentCrucibleActor.generated.h"

class USphereComponent;

/**
 * AAshenMagmaVentCrucibleActor
 * 
 * Spatial world actor in the volcanic caldera providing an active magma tempering node and periodic eruption hazard.
 */
UCLASS()
class ASHENOATH_API AAshenMagmaVentCrucibleActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMagmaVentCrucibleActor();

	virtual void BeginPlay() override;

	/** Ignites weapon tempering when player interacts with vent */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario7|World")
	void ChannelWeaponTempering();

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|World")
	ECalderaSurgePhase GetCurrentSurgePhase() const { return CurrentPhase; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* CrucibleMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* TemperingInteractRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Scenario7")
	ECalderaSurgePhase CurrentPhase = ECalderaSurgePhase::DormantCalm;
};

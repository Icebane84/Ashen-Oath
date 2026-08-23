// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AAshenPinnedScoutWorldActor.generated.h"

class USphereComponent;

/**
 * AAshenPinnedScoutWorldActor
 * 
 * Physicalized corrupted Order scout pinned beneath stone rubble at the dormant Heartstone waystation.
 */
UCLASS()
class ASHENOATH_API AAshenPinnedScoutWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenPinnedScoutWorldActor();

	virtual void BeginPlay() override;

	/** Applies catalyst decision to pinned scout */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Waystation")
	void ApplyCatalystDecision(EScoutCatalystDecision Decision);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Waystation")
	EScoutCatalystDecision GetScoutStatus() const { return CurrentStatus; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* InteractionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|World|Waystation")
	EScoutCatalystDecision CurrentStatus = EScoutCatalystDecision::HarvestResidualTaint;
};

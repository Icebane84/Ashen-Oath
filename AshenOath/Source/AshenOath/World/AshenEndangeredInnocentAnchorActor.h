// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenEndangeredInnocentAnchorActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

/**
 * AAshenEndangeredInnocentAnchorActor
 * 
 * 3D world encounter entity representing an innocent civilian or wounded ally
 * under immediate enemy threat, triggering formation-break intent evaluation.
 */
UCLASS()
class ASHENOATH_API AAshenEndangeredInnocentAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenEndangeredInnocentAnchorActor();

	virtual void BeginPlay() override;

	/** Checks if player entered danger radius to trigger rescue intent */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Innocent")
	void TriggerRescueEncounter();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Innocent")
	bool IsEncounterActive() const { return bIsActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* DangerRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* InnocentMesh;

private:
	bool bIsActive = true;
};

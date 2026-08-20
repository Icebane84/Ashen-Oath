// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenStaggeredEliteAnchorActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

/**
 * AAshenStaggeredEliteAnchorActor
 * 
 * 3D world encounter entity representing a staggered foe, exposing interaction
 * prompts for Merciful Binding or Ruthless Execution.
 */
UCLASS()
class ASHENOATH_API AAshenStaggeredEliteAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenStaggeredEliteAnchorActor();

	virtual void BeginPlay() override;

	/** Resolves the staggered encounter */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Stagger")
	void ResolveStagger(EFoeStaggerResolutionChoice Choice);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Stagger")
	bool IsStaggerAwaitingResolution() const { return bAwaitingResolution; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Stagger")
	bool IsTargetHumanoid() const { return bIsHumanoid; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Stagger")
	float GetThreatRating() const { return ThreatRating; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* InteractionRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* EnemyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Stagger")
	bool bIsHumanoid = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Stagger")
	float ThreatRating = 0.75f;

private:
	bool bAwaitingResolution = true;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWorldObstacleAnchorActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

/**
 * AAshenWorldObstacleAnchorActor
 * 
 * 3D world obstacle entity (civilian rubble, collapsed timber) that
 * high-trust companions proactively clear before Kaelen arrives.
 */
UCLASS()
class ASHENOATH_API AAshenWorldObstacleAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenWorldObstacleAnchorActor();

	virtual void BeginPlay() override;

	/** Clears the obstacle */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Obstacle")
	void ClearObstacle();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Obstacle")
	bool IsObstacleCleared() const { return bIsCleared; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Obstacle")
	bool IsCivilianTrapped() const { return bTrapsCivilian; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* InteractionRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* RubbleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Obstacle")
	bool bTrapsCivilian = true;

private:
	bool bIsCleared = false;
};

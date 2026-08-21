// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenTripartiteFinisherAnchorActor.generated.h"

class USphereComponent;

/**
 * AAshenTripartiteFinisherAnchorActor
 * 
 * 3D world anchor entity managing staging radius and cinematic camera tracking
 * during 3-person harmonized finishers.
 */
UCLASS()
class ASHENOATH_API AAshenTripartiteFinisherAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenTripartiteFinisherAnchorActor();

	virtual void BeginPlay() override;

	/** Triggers cinematic staging sequence */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Trio")
	void TriggerFinisherStaging(AActor* TargetActor);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Trio")
	bool IsStagingActive() const { return bStagingActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* FinisherRadius;

private:
	bool bStagingActive = false;
};

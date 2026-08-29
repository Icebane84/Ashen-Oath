// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AAshenStanceTrainingTargetWorldActor.generated.h"

/**
 * AAshenStanceTrainingTargetWorldActor
 * 
 * Specialized combat dummy actor placed in the training sanctuary and Memory Palace to practice 4-guard stance combos, counter-bind parries, and Flow Glint cancels.
 */
UCLASS()
class ASHENOATH_API AAshenStanceTrainingTargetWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenStanceTrainingTargetWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Stance")
	void RegisterStanceHit(EOathbringerMartialStance Stance, float Damage, float PoiseDamage);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Stance")
	int32 GetTotalHitsReceived() const { return TotalHitsReceived; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|World|Stance")
	int32 TotalHitsReceived = 0;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AAshenTrainingDummyKinematicsWorldActor.generated.h"

/**
 * AAshenTrainingDummyKinematicsWorldActor
 * 
 * Interactive training combat automaton actor for testing deflection windows, poise break stagger thresholds, and weight class rolls.
 */
UCLASS()
class ASHENOATH_API AAshenTrainingDummyKinematicsWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenTrainingDummyKinematicsWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics")
	float GetDummyMaxPoise() const { return MaxPoise; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics")
	float GetCurrentPoise() const { return CurrentPoise; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Kinematics")
	float MaxPoise = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Kinematics")
	float CurrentPoise = 100.0f;
};

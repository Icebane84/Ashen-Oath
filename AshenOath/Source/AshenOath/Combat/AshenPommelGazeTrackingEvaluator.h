// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenPommelGazeTrackingEvaluator.generated.h"

/**
 * UAshenPommelGazeTrackingEvaluator
 * 
 * Computes the look-at rotation vectors for the dual garnet eyes embedded in the wolf-head pommel and evaluates weeping bile emission.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPommelGazeTrackingEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPommelGazeTrackingEvaluator();

	/** Calculates look-at rotator from pommel socket to target */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Pommel")
	FRotator EvaluatePommelGazeRotation(const FVector& PommelLocation, const FVector& TargetLocation) const;

	/** Evaluates garnet eye emissive intensity [0.10 to 1.00] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Pommel")
	float EvaluatePommelEmissiveGlow(float Corruption01) const;

	/** Determines if pommel is weeping dark bile (corruption >= 0.70) */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Pommel")
	bool IsWeepingBile(float Corruption01) const;
};

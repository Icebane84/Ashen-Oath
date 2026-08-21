// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenRelicInspectionEvaluatorComponent.generated.h"

/**
 * UAshenRelicInspectionEvaluatorComponent
 * 
 * Computes 3D relic rotation angles and inscription revelation progression.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelicInspectionEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelicInspectionEvaluatorComponent();

	/** Evaluates whether looking at the relic angle reveals the hidden inscription */
	UFUNCTION(BlueprintPure, Category = "Ashen|Archive")
	bool EvaluateSecretAngleAlignment(
		float CurrentYawDegrees,
		float TargetYawDegrees,
		float ToleranceDegrees) const;

	/** Evaluates decoded percentage based on inspection dwell time */
	UFUNCTION(BlueprintPure, Category = "Ashen|Archive")
	float EvaluateDecodedPercentage(float DwellTimeSeconds, float RequiredTimeSeconds) const;
};

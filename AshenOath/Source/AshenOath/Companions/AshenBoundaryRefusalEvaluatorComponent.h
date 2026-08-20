// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenBoundaryRefusalEvaluatorComponent.generated.h"

/**
 * UAshenBoundaryRefusalEvaluatorComponent
 * 
 * Evaluates whether high-trust companions should execute boundary refusals
 * when Kaelen exhibits reckless suicidal self-destruction.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBoundaryRefusalEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBoundaryRefusalEvaluatorComponent();

	/** Evaluates boundary standoff state */
	UFUNCTION(BlueprintPure, Category = "Ashen|Silence")
	ECompanionBoundaryState EvaluateBoundary(
		FName CompanionName,
		float CompanionTrust,
		float KaelenDysregulation,
		bool bIsSuicidalCharge) const;
};

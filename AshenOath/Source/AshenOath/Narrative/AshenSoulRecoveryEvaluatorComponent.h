// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenSoulRecoveryEvaluatorComponent.generated.h"

/**
 * UAshenSoulRecoveryEvaluatorComponent
 * 
 * Evaluates integration debt and dysregulation levels to categorize rest sessions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulRecoveryEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulRecoveryEvaluatorComponent();

	/** Evaluates rest tier and generates session snapshot */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Hearth")
	FCampfireIntegrationSnapshot EvaluateRestSession(float IntegrationDebt, float Dysregulation) const;
};

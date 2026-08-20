// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenStaggerResolutionEvaluatorComponent.generated.h"

/**
 * UAshenStaggerResolutionEvaluatorComponent
 * 
 * Evaluates companion reactions to Mercy vs Execution:
 * - Garrett approves execution on lethal monsters, condemns senseless cruelty.
 * - Serafina praises mercy/purification, carries moral grief on execution.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStaggerResolutionEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStaggerResolutionEvaluatorComponent();

	/** Evaluates moral and pragmatic consequences of the choice */
	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Morality")
	FMercyExecutionEvaluationResult EvaluateChoice(
		EFoeStaggerResolutionChoice ChoiceMade,
		bool bTargetIsHumanoid,
		float TargetThreatLevel) const;
};

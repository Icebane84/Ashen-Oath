// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionCombatDisagreementEvaluator.generated.h"

/**
 * UAshenCompanionCombatDisagreementEvaluator
 * Triggers verbal disagreement barks when target selection clashes with companion ethos.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionCombatDisagreementEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionCombatDisagreementEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	bool EvaluateTargetEthosClash(const FSoulStateVector& StateVector, bool bIsNonHostileTarget);
};

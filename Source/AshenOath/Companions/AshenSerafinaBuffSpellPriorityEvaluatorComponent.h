// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaBuffSpellPriorityEvaluatorComponent.generated.h"

/**
 * UAshenSerafinaBuffSpellPriorityEvaluatorComponent
 * Evaluates party combat status to select optimal support buff.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaBuffSpellPriorityEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaBuffSpellPriorityEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FName EvaluateOptimalBuffSpell(float KaelenStaminaPct, int32 SurroundingEnemyCount, float SerafinaTrustInKaelen);
};

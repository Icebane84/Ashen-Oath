// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaCoopComboStateTreeEvaluator.generated.h"

/**
 * UAshenSerafinaCoopComboStateTreeEvaluator
 * Evaluates Serafina co-op combo opportunity windows in StateTree tasks.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaCoopComboStateTreeEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaCoopComboStateTreeEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	bool EvaluateComboOpportunity(float SerafinaTrust, float StaggeredEnemyDistance) const;
};

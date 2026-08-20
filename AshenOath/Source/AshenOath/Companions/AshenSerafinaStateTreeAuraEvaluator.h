// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaStateTreeAuraEvaluator.generated.h"

/**
 * UAshenSerafinaStateTreeAuraEvaluator
 * Evaluates Serafina aura activation criteria in StateTree tasks based on SerafinaTrust.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaStateTreeAuraEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaStateTreeAuraEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	bool ShouldActivateAura(float SerafinaTrust, float PlayerHealthPct) const;
};

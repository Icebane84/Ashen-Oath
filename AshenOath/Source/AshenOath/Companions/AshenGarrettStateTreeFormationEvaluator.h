// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettStateTreeFormationEvaluator.generated.h"

/**
 * UAshenGarrettStateTreeFormationEvaluator
 * Evaluates Garrett AI formation distance in StateTree tasks based on GarrettTrust.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettStateTreeFormationEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettStateTreeFormationEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float CalculateFormationRadius(float GarrettTrust) const;
};

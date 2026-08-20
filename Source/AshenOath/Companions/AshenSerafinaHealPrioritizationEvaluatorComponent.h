// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaHealPrioritizationEvaluatorComponent.generated.h"

/**
 * UAshenSerafinaHealPrioritizationEvaluatorComponent
 * Evaluates party member health and trust to prioritize healing spells.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaHealPrioritizationEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaHealPrioritizationEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	AActor* EvaluateHealTarget(AActor* KaelenActor, AActor* GarrettActor, float KaelenHealthPct, float GarrettHealthPct, float SerafinaTrustInKaelen);
};

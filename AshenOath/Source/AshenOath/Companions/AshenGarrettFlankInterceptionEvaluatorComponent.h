// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettFlankInterceptionEvaluatorComponent.generated.h"

/**
 * UAshenGarrettFlankInterceptionEvaluatorComponent
 * Evaluates enemy flank vectors to position Garrett for interception.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettFlankInterceptionEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettFlankInterceptionEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FVector EvaluateInterceptionPosition(const FVector& KaelenLocation, const FVector& FlankingEnemyLocation, float GarrettTrust);
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemorySequenceUnlockEvaluator.generated.h"

/**
 * UAshenMemorySequenceUnlockEvaluator
 * Evaluator evaluating memory unlock triggers (Eldrin's Grace, Parental Protection, Valerius's Kindness, Eldrin's Research).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemorySequenceUnlockEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMemorySequenceUnlockEvaluator();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool EvaluateMemorySequenceEligibility(FName MemoryID, float IntegrationDebt);
};

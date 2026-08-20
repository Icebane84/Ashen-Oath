// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenMindscapeTransitionPhenotypeEvaluator.generated.h"

/**
 * UAshenMindscapeTransitionPhenotypeEvaluator
 * Evaluates forced Mindscape transition criteria when IntegrationDebt hits 1.0.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMindscapeTransitionPhenotypeEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMindscapeTransitionPhenotypeEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mindscape")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mindscape")
	bool ShouldTriggerMindscapeTransition() const { return bTriggerMindscape; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Mindscape")
	bool bTriggerMindscape = false;
};

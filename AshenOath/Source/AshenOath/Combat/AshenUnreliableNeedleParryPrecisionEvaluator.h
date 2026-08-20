// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUnreliableNeedleParryPrecisionEvaluator.generated.h"

/**
 * UAshenUnreliableNeedleParryPrecisionEvaluator
 * Evaluates parry precision tolerance based on Isolation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedleParryPrecisionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliableNeedleParryPrecisionEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetParryWindowMarginSeconds() const { return ParryWindowMarginSeconds; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float ParryWindowMarginSeconds = 0.20f;
};

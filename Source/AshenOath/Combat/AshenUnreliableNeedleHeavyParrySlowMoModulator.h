// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUnreliableNeedleHeavyParrySlowMoModulator.generated.h"

/**
 * UAshenUnreliableNeedleHeavyParrySlowMoModulator
 * Modulates slow-motion duration during heavy parries based on Isolation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedleHeavyParrySlowMoModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliableNeedleHeavyParrySlowMoModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetSlowMoTimeDilation() const { return SlowMoTimeDilation; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float SlowMoTimeDilation = 0.2f;
};

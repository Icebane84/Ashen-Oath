// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticStaminaRecoveryRateModulator.generated.h"

/**
 * UAshenDiegeticStaminaRecoveryRateModulator
 * Binds stamina recharge delay to Resolve.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticStaminaRecoveryRateModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticStaminaRecoveryRateModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetStaminaRechargeDelayMultiplier() const { return RechargeDelayMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float RechargeDelayMultiplier = 1.0f;
};

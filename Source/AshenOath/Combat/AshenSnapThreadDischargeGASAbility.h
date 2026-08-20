// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSnapThreadDischargeGASAbility.generated.h"

/**
 * UAshenSnapThreadDischargeGASAbility
 * GAS ability releasing a violent kinetic radial shockwave when an over-tensioned aegis thread ruptures under kinetic load (650.0 DMG in 400uu).
 */
UCLASS()
class ASHENOATH_API UAshenSnapThreadDischargeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSnapThreadDischargeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float RadialDischargeDamage = 650.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float BlastRadiusUnits = 400.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool TriggerThreadSnapDischarge(FVector RuptureLocation);
};

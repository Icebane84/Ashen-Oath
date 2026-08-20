// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenBerserkRendGASAbility.generated.h"

/**
 * UAshenBerserkRendGASAbility
 * GAS ability executing a 3-hit forward cleave combo (120 -> 180 -> 300 DMG) accelerating attack speed by 10% per hit.
 */
UCLASS()
class ASHENOATH_API UAshenBerserkRendGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenBerserkRendGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	TArray<float> ComboHitsDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float AttackSpeedAccelerationPerHit = 0.10f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float CalculateComboDamage(int32 HitIndex, float& OutSpeedBonus) const;
};

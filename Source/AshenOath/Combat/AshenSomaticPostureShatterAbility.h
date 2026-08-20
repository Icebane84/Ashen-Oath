// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSomaticPostureShatterAbility.generated.h"

/**
 * UAshenSomaticPostureShatterAbility
 * Gameplay Ability executing a somatic posture stance shatter wave piercing enemy stance guard.
 */
UCLASS()
class ASHENOATH_API UAshenSomaticPostureShatterAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSomaticPostureShatterAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float PostureShatterDamage = 250.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerSomaticPostureShatterStrike();
};

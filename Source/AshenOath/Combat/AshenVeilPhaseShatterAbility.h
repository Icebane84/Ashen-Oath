// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenVeilPhaseShatterAbility.generated.h"

/**
 * UAshenVeilPhaseShatterAbility
 * Gameplay Ability executing a dimensional veil phase shatter strike piercing enemy physical defenses.
 */
UCLASS()
class ASHENOATH_API UAshenVeilPhaseShatterAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenVeilPhaseShatterAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float PhaseShatterDamage = 180.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerVeilPhaseShatterStrike();
};

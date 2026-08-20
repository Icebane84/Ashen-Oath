// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenVeilPhaseFilterShatterAbility.generated.h"

/**
 * UAshenVeilPhaseFilterShatterAbility
 * Gameplay Ability executing a dimensional veil phase filter shatter strike piercing enemy defense layers.
 */
UCLASS()
class ASHENOATH_API UAshenVeilPhaseFilterShatterAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenVeilPhaseFilterShatterAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float VeilPhaseFilterShatterDamage = 230.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerVeilPhaseFilterShatterStrike();
};

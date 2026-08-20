// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenPunishWindowCounterAbility.generated.h"

/**
 * UAshenPunishWindowCounterAbility
 * Gameplay Ability executing a punish-window counter strike when AI evaluates player vulnerability windows.
 */
UCLASS()
class ASHENOATH_API UAshenPunishWindowCounterAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPunishWindowCounterAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float PunishCounterDamage = 280.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerPunishCounterStrike();
};

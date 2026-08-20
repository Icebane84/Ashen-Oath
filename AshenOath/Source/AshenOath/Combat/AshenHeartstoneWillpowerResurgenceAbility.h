// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenHeartstoneWillpowerResurgenceAbility.generated.h"

/**
 * UAshenHeartstoneWillpowerResurgenceAbility
 * Gameplay Ability executing Heartstone Sanctuary willpower resurgence, resetting static noise and attuning companion synergy.
 */
UCLASS()
class ASHENOATH_API UAshenHeartstoneWillpowerResurgenceAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHeartstoneWillpowerResurgenceAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float SanctuaryResurgenceHealAmount = 500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerSanctuaryResurgence();
};

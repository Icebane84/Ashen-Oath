// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSovereignPhoenixFlameAscensionAbility.generated.h"

/**
 * UAshenSovereignPhoenixFlameAscensionAbility
 * Pinnacle Gameplay Ability executing "Ascension of the White Flame — Sovereign Phoenix Burst".
 */
UCLASS()
class ASHENOATH_API UAshenSovereignPhoenixFlameAscensionAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSovereignPhoenixFlameAscensionAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float SovereignWhiteFlameBurstDamage = 1100.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerSovereignPhoenixFlameAscension();
};

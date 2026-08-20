// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSovereignPhoenixShatterAbility.generated.h"

/**
 * UAshenSovereignPhoenixShatterAbility
 * Gameplay Ability executing a sovereign phoenix shatter shockwave annihilating enemy defense barriers.
 */
UCLASS()
class ASHENOATH_API UAshenSovereignPhoenixShatterAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSovereignPhoenixShatterAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float SovereignShatterDamage = 350.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerSovereignPhoenixShatterWave();
};

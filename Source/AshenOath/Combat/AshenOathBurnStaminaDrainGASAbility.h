// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenOathBurnStaminaDrainGASAbility.generated.h"

/**
 * UAshenOathBurnStaminaDrainGASAbility
 * GAS ability applying the active Oath Burn debuff state when OathBurden >= 1.0f.
 */
UCLASS()
class ASHENOATH_API UAshenOathBurnStaminaDrainGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenOathBurnStaminaDrainGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ActivateOathBurnDebuffState();
};

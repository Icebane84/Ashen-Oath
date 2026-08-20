// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenUnreliableNarratorGASAbility.generated.h"

/**
 * UAshenUnreliableNarratorGASAbility
 * GAS Ability resisting/clearing environmental illusions via willpower pulse.
 */
UCLASS()
class ASHENOATH_API UAshenUnreliableNarratorGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenUnreliableNarratorGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool DispelHallucinatoryMirage();
};

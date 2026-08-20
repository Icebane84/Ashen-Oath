// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenAlchemicalLanternGASAbility.generated.h"

/**
 * UAshenAlchemicalLanternGASAbility
 * GAS Ability toggling lantern illumination beam and burning fuel.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalLanternGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenAlchemicalLanternGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lantern GAS")
	bool ActivateLanternBeam();
};

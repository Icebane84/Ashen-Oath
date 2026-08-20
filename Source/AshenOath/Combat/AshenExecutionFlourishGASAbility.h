// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenExecutionFlourishGASAbility.generated.h"

/**
 * UAshenExecutionFlourishGASAbility
 * GAS Gameplay Ability executing stance-specific finishers on staggered foes.
 */
UCLASS()
class ASHENOATH_API UAshenExecutionFlourishGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenExecutionFlourishGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ExecuteStanceFinisher(uint8 StanceEnum);
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenDebtForcedCollapseGASAbility.generated.h"

/**
 * UAshenDebtForcedCollapseGASAbility
 * GAS ability handling the forced Mindscape collapse invocation state when IntegrationDebt >= 1.0f.
 */
UCLASS()
class ASHENOATH_API UAshenDebtForcedCollapseGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenDebtForcedCollapseGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ExecuteForcedCollapseAbility();
};

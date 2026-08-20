// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSerafinaTransferenceGASAbility.generated.h"

/**
 * UAshenSerafinaTransferenceGASAbility
 * GAS Gameplay Ability channeling soul transference.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaTransferenceGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSerafinaTransferenceGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ActivateTransferenceAbility(AActor* TargetAlly, float HealingPower);
};

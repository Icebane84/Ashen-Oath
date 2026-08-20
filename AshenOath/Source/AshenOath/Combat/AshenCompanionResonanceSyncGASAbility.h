// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenCompanionResonanceSyncGASAbility.generated.h"

/**
 * UAshenCompanionResonanceSyncGASAbility
 * GAS ability granting the 15s team damage bonus and poise armor during active ResonanceSync.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionResonanceSyncGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenCompanionResonanceSyncGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ActivateResonanceSyncDamageBuff();
};

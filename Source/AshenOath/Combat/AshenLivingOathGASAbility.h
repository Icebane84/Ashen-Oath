// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenLivingOathGASAbility.generated.h"

/**
 * UAshenLivingOathGASAbility
 * GAS ability unleashing empowered oath resonance strikes and temporary buff auras based on active Living Oath.
 */
UCLASS()
class ASHENOATH_API UAshenLivingOathGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenLivingOathGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Oath GAS")
	float OathResonanceBonusDamage = 180.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Oath GAS")
	bool ActivateOathStrike(EAshenLivingOathType OathType);
};

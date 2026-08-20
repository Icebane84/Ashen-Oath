// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenTransferenceShieldGASAbility.generated.h"

/**
 * UAshenTransferenceShieldGASAbility
 * GAS ability creating a psychic transference barrier absorbing 400.0 damage and restoring companion sanity by 25% of blocked damage.
 */
UCLASS()
class ASHENOATH_API UAshenTransferenceShieldGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenTransferenceShieldGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float MaxShieldAbsorption = 400.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SanityConversionRatio = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float AbsorbDamageAndConvert(float IncomingDamage, float& OutSanityRestored);
};

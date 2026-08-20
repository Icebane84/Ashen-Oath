// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSomaticIdentityShatterAbility.generated.h"

/**
 * UAshenSomaticIdentityShatterAbility
 * Gameplay Ability executing a somatic identity shatter wave disrupting enemy posture and psychological resolve.
 */
UCLASS()
class ASHENOATH_API UAshenSomaticIdentityShatterAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSomaticIdentityShatterAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float IdentityShatterDamage = 210.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerSomaticIdentityShatterWave();
};

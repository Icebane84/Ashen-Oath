// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenWhiteFlameSurgeGASAbility.generated.h"

/**
 * UAshenWhiteFlameSurgeGASAbility
 * Gameplay Ability executing the White Flame Surge counter-attack following Path B restraint.
 */
UCLASS()
class ASHENOATH_API UAshenWhiteFlameSurgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWhiteFlameSurgeGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float WhiteFlameSurgeDamage = 320.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerWhiteFlameSurgeStrike();
};

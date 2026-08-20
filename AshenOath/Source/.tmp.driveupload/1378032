// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSovereignPhoenixAscensionAbility.generated.h"

/**
 * UAshenSovereignPhoenixAscensionAbility
 * Flagship Gameplay Ability—"Ascension of the White Flame"—unleashing a map-wide holy purification shockwave, restoring companion trust, and applying DualSense haptic friction.
 */
UCLASS()
class ASHENOATH_API UAshenSovereignPhoenixAscensionAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSovereignPhoenixAscensionAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float AscensionPurificationRadius = 1500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerSovereignPhoenixAscension();
};

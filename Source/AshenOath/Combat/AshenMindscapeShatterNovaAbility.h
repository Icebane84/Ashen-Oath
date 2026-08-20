// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenMindscapeShatterNovaAbility.generated.h"

/**
 * UAshenMindscapeShatterNovaAbility
 * Gameplay Ability unleashing a psychic mindscape shatter nova dealing area damage and staggering enemy posture.
 */
UCLASS()
class ASHENOATH_API UAshenMindscapeShatterNovaAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMindscapeShatterNovaAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float ShatterNovaDamage = 150.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerShatterNovaExecution();
};

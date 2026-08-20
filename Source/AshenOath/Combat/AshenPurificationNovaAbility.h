// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenPurificationNovaAbility.generated.h"

/**
 * UAshenPurificationNovaAbility
 * Gameplay Ability triggering a radiant holy purification nova to cleanse environmental miasma and stagger corrupt entities.
 */
UCLASS()
class ASHENOATH_API UAshenPurificationNovaAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPurificationNovaAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float PurificationNovaRadius = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerPurificationNovaPulse();
};

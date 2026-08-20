// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSovereignDualityTransformationAbility.generated.h"

/**
 * UAshenSovereignDualityTransformationAbility
 * Gameplay Ability executing Kaelen's real-time Light Mode ↔ Dark Mode duality transformation.
 */
UCLASS()
class ASHENOATH_API UAshenSovereignDualityTransformationAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSovereignDualityTransformationAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float TransformationPulseRadius = 1000.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerDualityTransformationPulse();
};

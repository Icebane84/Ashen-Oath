// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenShadowMarkCorruptionGASAbility.generated.h"

/**
 * UAshenShadowMarkCorruptionGASAbility
 * GAS ability triggering Shadow Mark C max saturation burst.
 */
UCLASS()
class ASHENOATH_API UAshenShadowMarkCorruptionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenShadowMarkCorruptionGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ActivateShadowMarkBurst();
};

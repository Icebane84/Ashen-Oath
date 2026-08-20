// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenMemoryPalaceResonanceGASAbility.generated.h"

/**
 * UAshenMemoryPalaceResonanceGASAbility
 * GAS ability triggering a psychic pulse that reveals hidden memory echo threads and purges nightmare phantom stealth.
 */
UCLASS()
class ASHENOATH_API UAshenMemoryPalaceResonanceGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenMemoryPalaceResonanceGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Memory")
	float ResonancePulseRadius = 1800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool UnleashResonancePulse(AActor* InstigatorActor);
};

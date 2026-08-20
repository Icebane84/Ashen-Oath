// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenResonanceSyncGASAbility.generated.h"

/**
 * UAshenResonanceSyncGASAbility
 * GAS ability applying the 30-second +15% Resonance damage bonus surge and blade glow upon full trio alignment.
 */
UCLASS()
class ASHENOATH_API UAshenResonanceSyncGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenResonanceSyncGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Resonance")
	float ResonanceDuration = 30.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Resonance")
	float DamageMultiplierBonus = 0.15f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Resonance")
	bool UnleashResonanceSurge(AActor* InstigatorActor);
};

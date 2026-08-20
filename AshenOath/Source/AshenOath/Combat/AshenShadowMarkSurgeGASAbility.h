// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenShadowMarkSurgeGASAbility.generated.h"

/**
 * UAshenShadowMarkSurgeGASAbility
 * Combat surge ability unlocking Kaelen's unchained vessel state, triggering crimson static discharge and granting +40% dark melee damage for 10.0s.
 */
UCLASS()
class ASHENOATH_API UAshenShadowMarkSurgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenShadowMarkSurgeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float DarkDamageMultiplier = 1.40f; // +40%

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SurgeDuration = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float MinCorruptionRequired = 0.70f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool UnleashShadowMarkSurge(AActor* InstigatorActor, float CurrentCorruption);
};

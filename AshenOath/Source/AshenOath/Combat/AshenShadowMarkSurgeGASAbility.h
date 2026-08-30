// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenShadowMarkSurgeGASAbility.generated.h"

class UAshenSoulPublisher;

/**
 * UAshenShadowMarkSurgeGASAbility
 * Combat surge ability unlocking Kaelen's unchained vessel state, triggering crimson
 * static discharge and granting +40% dark melee damage for 10.0s, gated by SSoT Corruption >= 0.70.
 */
UCLASS()
class ASHENOATH_API UAshenShadowMarkSurgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenShadowMarkSurgeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath|Combat")
	float DarkDamageMultiplier = 1.40f; // +40%

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath|Combat")
	float SurgeDuration = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath|Combat")
	float MinCorruptionRequired = 0.70f;

	/** Unleashes surge, querying authoritative corruption from UAshenSoulPublisher */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Combat")
	bool UnleashShadowMarkSurge(AActor* InstigatorActor);

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};

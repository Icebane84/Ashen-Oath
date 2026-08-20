// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenUnchainedRageMode.generated.h"

/**
 * UGA_KaelenUnchainedRageMode
 *
 * Kaelen's ultimate berserk unchained rage ability.
 * Grants +60% Physical damage, +40% Attack speed, and 30% Damage resistance for 12.0s.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenUnchainedRageMode : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenUnchainedRageMode();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|UnchainedRage")
	float DamageBonusPercentage = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|UnchainedRage")
	float RageDuration = 12.0f;
};

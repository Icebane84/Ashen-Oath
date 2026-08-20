// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenUnchainedBerserkMode.generated.h"

/**
 * UGA_KaelenUnchainedBerserkMode
 *
 * Kaelen's ultimate berserk transformation state ability.
 * Grants +50% Physical damage, +30% movement speed, and 0 poise damage taken for 10 seconds.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenUnchainedBerserkMode : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenUnchainedBerserkMode();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Berserk")
	float Duration = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Berserk")
	float DamageBuffMultiplier = 1.50f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Berserk")
	float SpeedBuffMultiplier = 1.30f;
};

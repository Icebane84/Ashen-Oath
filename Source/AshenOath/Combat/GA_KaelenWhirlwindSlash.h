// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenWhirlwindSlash.generated.h"

/**
 * UGA_KaelenWhirlwindSlash
 *
 * Kaelen's 360° spinning multi-hit area attack.
 * Deals 280 Physical damage to all enemies within 450 units and knocks back hit targets.
 * Costs 45 Stamina. Uses UKismetSystemLibrary::SphereOverlapActors.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenWhirlwindSlash : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenWhirlwindSlash();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Whirlwind")
	float Damage = 280.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Whirlwind")
	float Radius = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Whirlwind")
	float StaminaCost = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Whirlwind")
	float KnockbackImpulse = 800.0f;
};

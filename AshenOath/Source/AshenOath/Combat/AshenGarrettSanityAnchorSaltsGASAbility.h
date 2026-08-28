// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenGarrettSanityAnchorSaltsGASAbility.generated.h"

/**
 * UAshenGarrettSanityAnchorSaltsGASAbility
 * 
 * Garrett's field alchemy: Administers pungent ember-salts to wielder, freezing sanity decay for 12.0s.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettSanityAnchorSaltsGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettSanityAnchorSaltsGASAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Convergence")
	float AnchorDurationSeconds = 12.0f;
};

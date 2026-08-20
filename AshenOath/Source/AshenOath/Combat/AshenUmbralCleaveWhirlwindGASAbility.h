// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenUmbralCleaveWhirlwindGASAbility.generated.h"

/**
 * UAshenUmbralCleaveWhirlwindGASAbility
 * 
 * 360-degree continuous greatsword whirlwind releasing massive kinetic shockwaves.
 */
UCLASS()
class ASHENOATH_API UAshenUmbralCleaveWhirlwindGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenUmbralCleaveWhirlwindGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Whirlwind")
	float WhirlwindRadiusUU = 450.0f;
};

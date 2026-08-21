// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenUmbralCataclysmMeltdownGASAbility.generated.h"

/**
 * UAshenUmbralCataclysmMeltdownGASAbility
 * 
 * Boss Phase 3 meltdown ultimate unleashing arena-wide umbral pulses.
 */
UCLASS()
class ASHENOATH_API UAshenUmbralCataclysmMeltdownGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenUmbralCataclysmMeltdownGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Boss|Combat")
	float MeltdownTickRateSeconds = 1.0f;
};

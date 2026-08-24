// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenGarrettRubbleVaultGASAbility.generated.h"

/**
 * UAshenGarrettRubbleVaultGASAbility
 * 
 * Garrett vaults over dynamic low rubble without dropping combat momentum.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettRubbleVaultGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettRubbleVaultGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Garrett")
	float MaxVaultHeightUU = 120.0f;
};

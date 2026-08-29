// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenDecapitationExecutionGASAbility.generated.h"

/**
 * UAshenDecapitationExecutionGASAbility
 * 
 * Clean Decapitation: High-tier execution finisher targeting the head/neck socket, generating maximal fear panic on witness AI and granting +35.0 adrenaline.
 */
UCLASS()
class ASHENOATH_API UAshenDecapitationExecutionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenDecapitationExecutionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Severance")
	float DecapitationDamage = 600.0f;
};

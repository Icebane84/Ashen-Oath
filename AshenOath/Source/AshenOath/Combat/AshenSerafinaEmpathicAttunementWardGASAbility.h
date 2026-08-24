// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenSerafinaEmpathicAttunementWardGASAbility.generated.h"

/**
 * UAshenSerafinaEmpathicAttunementWardGASAbility
 * 
 * Serafina channels an empathic resonance ward that redistributes incoming damage equally across the trio (33% each).
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaEmpathicAttunementWardGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaEmpathicAttunementWardGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Serafina")
	float WardDurationSeconds = 6.0f;
};

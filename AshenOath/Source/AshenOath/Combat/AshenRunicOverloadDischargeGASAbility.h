// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicOverloadDischargeGASAbility.generated.h"

/**
 * UAshenRunicOverloadDischargeGASAbility
 * 
 * Vents excess runic heat from overcharged sockets, dealing point-blank AoE damage.
 */
UCLASS()
class ASHENOATH_API UAshenRunicOverloadDischargeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenRunicOverloadDischargeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Reliquary")
	float DischargeRadiusUU = 500.0f;
};

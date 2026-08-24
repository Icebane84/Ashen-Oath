// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenParasiticCleaveOverchargeGASAbility.generated.h"

/**
 * UAshenParasiticCleaveOverchargeGASAbility
 * 
 * Heavy cleave channeling Nyx's dark power into Oathbringer (+75% damage, +0.15 Integration Debt).
 */
UCLASS()
class ASHENOATH_API UAshenParasiticCleaveOverchargeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenParasiticCleaveOverchargeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Blade")
	float CleaveDamageBonusPercent = 0.75f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Blade")
	float IntegrationDebtCost = 0.15f;
};

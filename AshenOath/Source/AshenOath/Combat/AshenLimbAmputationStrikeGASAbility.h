// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenLimbAmputationStrikeGASAbility.generated.h"

/**
 * UAshenLimbAmputationStrikeGASAbility
 * 
 * Limb Amputation: Precision strike severing enemy arms (disarming weapon combos) or legs (crippling movement speed by 60%).
 */
UCLASS()
class ASHENOATH_API UAshenLimbAmputationStrikeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenLimbAmputationStrikeGASAbility();

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
	ESeveranceBoneTarget TargetLimb = ESeveranceBoneTarget::RightArm;
};

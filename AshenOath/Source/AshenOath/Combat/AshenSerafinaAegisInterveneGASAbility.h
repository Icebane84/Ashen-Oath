// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenSerafinaAegisInterveneGASAbility.generated.h"

/**
 * UAshenSerafinaAegisInterveneGASAbility
 * 
 * Orders Serafina to interpose between Kaelen and enemies with a sacred shield dome.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaAegisInterveneGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaAegisInterveneGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Tactics")
	float BarrierAbsorptionHealth = 600.0f;
};

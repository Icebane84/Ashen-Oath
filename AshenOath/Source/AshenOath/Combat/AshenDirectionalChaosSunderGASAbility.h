// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenDirectionalChaosSunderGASAbility.generated.h"

/**
 * UAshenDirectionalChaosSunderGASAbility
 * 
 * Downward overhead sunder ability projecting geometric cutting planes into
 * Chaos destructible collections.
 */
UCLASS()
class ASHENOATH_API UAshenDirectionalChaosSunderGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenDirectionalChaosSunderGASAbility();

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

	/** Calculates cutting plane equation Ax + By + Cz + D = 0 */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Chaos")
	FPlane CalculateCuttingPlane(const FVector& ImpactPoint, const FVector& CleaveDirection) const;
};

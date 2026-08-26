// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenGarrettEmberSaltPreserveGASAbility.generated.h"

/**
 * UAshenGarrettEmberSaltPreserveGASAbility
 * 
 * Garrett's field alchemy: Applies Ember Salts to fresh meat and herbs, curing rations and tripling shelf-life (3.0x).
 */
UCLASS()
class ASHENOATH_API UAshenGarrettEmberSaltPreserveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettEmberSaltPreserveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Cooking")
	float ShelfLifeMultiplier = 3.0f;
};

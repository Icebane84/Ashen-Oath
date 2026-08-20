// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenSacredOathReckoningStrikeGASAbility.generated.h"

/**
 * UAshenSacredOathReckoningStrikeGASAbility
 * 
 * High-damage holy strike empowered by remembered sacred vows (+20% Holy Damage).
 */
UCLASS()
class ASHENOATH_API UAshenSacredOathReckoningStrikeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSacredOathReckoningStrikeGASAbility();

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

	/** Executes reckoning strike on enemy target */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Vow")
	bool ExecuteReckoningStrike(AActor* TargetActor);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Vow")
	float HolyDamageMultiplier = 1.20f;
};

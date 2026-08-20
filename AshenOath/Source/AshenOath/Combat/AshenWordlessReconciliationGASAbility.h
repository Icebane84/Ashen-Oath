// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenWordlessReconciliationGASAbility.generated.h"

/**
 * UAshenWordlessReconciliationGASAbility
 * 
 * High-tier coordinated combat ability executing wordless reconciliation:
 * - Garrett and Kaelen execute a dual scissor flank strike
 * - Shatters enemy poise instantly (1500 Poise DMG)
 * - Transitions companion rupture state directly to RememberedReconciliation
 */
UCLASS()
class ASHENOATH_API UAshenWordlessReconciliationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWordlessReconciliationGASAbility();

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

	/** Executes the dual strike dealing lethal poise and physical damage */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Ecology")
	bool TriggerDualScissorStrike(AActor* TargetEnemy);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Ecology")
	float BasePoiseDamage = 1500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Ecology")
	float BasePhysicalDamage = 850.0f;
};

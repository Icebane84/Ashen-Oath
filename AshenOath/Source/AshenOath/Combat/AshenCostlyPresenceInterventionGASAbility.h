// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenCostlyPresenceInterventionGASAbility.generated.h"

/**
 * UAshenCostlyPresenceInterventionGASAbility
 * 
 * Gameplay Ability executing companion sacrificial intervention:
 * - Companion rushes across the battlefield at 1.45x sprint speed
 * - Slides in front of staggered Kaelen to parry or absorb the lethal blow
 * - Suffers physical damage and armor scarring while generating a high-tier cohesion imprint
 */
UCLASS()
class ASHENOATH_API UAshenCostlyPresenceInterventionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCostlyPresenceInterventionGASAbility();

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

	/** Executes the physical deflection and grants invulnerability frame to Kaelen */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Ecology")
	bool CompleteCostlyIntervention(float AbsorbedDamage);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Ecology")
	float InterceptSprintSpeedMultiplier = 1.45f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Ecology")
	float KaelenInvulnerabilityWindowSeconds = 1.50f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Ecology")
	float CompanionDamageMitigation = 0.50f;
};

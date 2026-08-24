// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenGarrettVoidAnchorGASAbility.generated.h"

/**
 * UAshenGarrettVoidAnchorGASAbility
 * 
 * Garrett fires kinetic pitons into the island bedrock, anchoring allies within 500uu against wind shear drift.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettVoidAnchorGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettVoidAnchorGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Garrett")
	float AnchorRadiusUU = 500.0f;
};

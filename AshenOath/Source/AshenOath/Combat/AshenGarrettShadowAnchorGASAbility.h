// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenGarrettShadowAnchorGASAbility.generated.h"

/**
 * UAshenGarrettShadowAnchorGASAbility
 * 
 * Step 2 of Trinity Strike: Garrett deploys Shadow Thread Pitons, anchoring the Shroud-Knight and locking out phase-shifting for 6 seconds.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettShadowAnchorGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettShadowAnchorGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Trinity")
	float AnchorLockoutDurationSeconds = 6.0f;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexBookmarkAnnotationGASAbility.generated.h"

/**
 * UAshenCodexBookmarkAnnotationGASAbility
 * 
 * Gameplay Ability creating custom bookmarks and marginalia pins in the codex.
 */
UCLASS()
class ASHENOATH_API UAshenCodexBookmarkAnnotationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCodexBookmarkAnnotationGASAbility();

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
};

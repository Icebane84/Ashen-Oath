// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenMarginaliaPenmanshipGASAbility.generated.h"

/**
 * UAshenMarginaliaPenmanshipGASAbility
 * 
 * Gameplay Ability triggered upon combat finisher execution or key trial moments,
 * stamping immediate penmanship marks into the active memory buffer.
 */
UCLASS()
class ASHENOATH_API UAshenMarginaliaPenmanshipGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMarginaliaPenmanshipGASAbility();

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

	/** Records immediate combat margin mark */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Journal")
	bool RecordCombatPenmanshipMark(const FString& TargetMemoryId, EMarginaliaAuthor Author);
};

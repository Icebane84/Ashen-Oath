// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenVeinCauterizationGASAbility.generated.h"

/**
 * UAshenVeinCauterizationGASAbility
 * 
 * Emergency white-flame cauterization burning away 0.25 vein corruption at the cost of stamina drain.
 */
UCLASS()
class ASHENOATH_API UAshenVeinCauterizationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenVeinCauterizationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Somatics")
	float CauterizedVeinAmount = 0.25f;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenSerafinaRadiantSanctuaryDomeGASAbility.generated.h"

/**
 * UAshenSerafinaRadiantSanctuaryDomeGASAbility
 * 
 * Serafina channels a glowing White Flame sanctuary barrier, providing 100% weather hazard immunity to all allies within 450uu.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaRadiantSanctuaryDomeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaRadiantSanctuaryDomeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Weather")
	float DomeRadiusUU = 450.0f;
};

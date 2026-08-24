// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenGroundSlamEcholocationGASAbility.generated.h"

/**
 * UAshenGroundSlamEcholocationGASAbility
 * 
 * Kaelen slams his greatsword into the cavern floor, generating an 1800uu acoustic sonar wave revealing terrain and enemies.
 */
UCLASS()
class ASHENOATH_API UAshenGroundSlamEcholocationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGroundSlamEcholocationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Echolocation")
	float SonarRadiusUU = 1800.0f;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenThermalShockShatterGASAbility.h"
#include "Combat/AshenAlchemicalSlagConvergenceSubsystem.h"
#include "Combat/AshenCombatCharacter.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenCharacterInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

UAshenThermalShockShatterGASAbility::UAshenThermalShockShatterGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	PoiseShatterMultiplier = 2.00f;
}

void UAshenThermalShockShatterGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}

	if (Avatar)
	{
		if (UWorld* World = Avatar->GetWorld())
		{
			// Reset soot battery after thermal shock shatter
			if (UAshenAlchemicalSlagConvergenceSubsystem* SlagSubsystem = World->GetSubsystem<UAshenAlchemicalSlagConvergenceSubsystem>())
			{
				SlagSubsystem->PolishBladeAtCampfire();
			}
		}

		if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Avatar))
		{
			CombatChar->TriggerStrikeImpact();
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UAshenThermalShockShatterGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

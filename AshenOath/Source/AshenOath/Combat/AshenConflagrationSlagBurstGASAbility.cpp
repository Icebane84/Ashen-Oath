// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenConflagrationSlagBurstGASAbility.h"
#include "Combat/AshenAlchemicalSlagConvergenceSubsystem.h"
#include "Combat/AshenCombatCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

UAshenConflagrationSlagBurstGASAbility::UAshenConflagrationSlagBurstGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	BlastDamage = 450.0f;
	BlastRadiusUU = 400.0f;
}

void UAshenConflagrationSlagBurstGASAbility::ActivateAbility(
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
			TArray<AActor*> IgnoredActors;
			IgnoredActors.Add(Avatar);

			// 450 Heat AoE Firestorm
			UGameplayStatics::ApplyRadialDamageWithFalloff(
				World,
				BlastDamage,
				BlastDamage * 0.40f,
				Avatar->GetActorLocation(),
				BlastRadiusUU * 0.25f,
				BlastRadiusUU,
				1.0f,
				UDamageType::StaticClass(),
				IgnoredActors,
				Avatar,
				nullptr
			);

			// Reset soot battery after deflagration
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

void UAshenConflagrationSlagBurstGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 439: GA_GarrettAssassinationExecution

#include "GA_GarrettAssassinationExecution.h"
#include "AshenOath_HealthComponent.h"
#include "AshenCompanionTrustDivergenceSubsystem.h"
#include "Engine/World.h"

UGA_GarrettAssassinationExecution::UGA_GarrettAssassinationExecution()
{
	Damage = 850.0f;
}

void UGA_GarrettAssassinationExecution::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	AActor* Owner = ActorInfo->OwnerActor.Get();
	if (!Owner)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	if (TriggerEventData && TriggerEventData->Target)
	{
		AActor* Target = const_cast<AActor*>(TriggerEventData->Target.Get());
		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->ReceiveDamage(Damage, Owner);

			if (UWorld* World = Owner->GetWorld())
			{
				if (UAshenCompanionTrustDivergenceSubsystem* Trust = World->GetSubsystem<UAshenCompanionTrustDivergenceSubsystem>())
				{
					Trust->RecordTrustShift(FName(TEXT("Companion_Garrett")), 20.0f);
				}
			}
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettAssassinationExecution: GARRETT STEALTH EXECUTION — %.0f damage applied."), Damage);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

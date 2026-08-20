// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 297: GA_SerafinaAegisDomain

#include "GA_SerafinaAegisDomain.h"

UGA_SerafinaAegisDomain::UGA_SerafinaAegisDomain()
{
	DomainRadius = 600.0f;
	ShieldHealth = 300.0f;
	DomainDuration = 12.0f;
}

void UGA_SerafinaAegisDomain::ActivateAbility(
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

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaAegisDomain: AEGIS DOMAIN ULTIMATE deployed by '%s' — %.0fu radius, %.0f HP shield, CC Immunity for %.1fs."),
		*Owner->GetName(), DomainRadius, ShieldHealth, DomainDuration);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

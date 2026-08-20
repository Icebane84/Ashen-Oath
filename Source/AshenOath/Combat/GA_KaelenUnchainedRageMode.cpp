// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 292: GA_KaelenUnchainedRageMode

#include "GA_KaelenUnchainedRageMode.h"

UGA_KaelenUnchainedRageMode::UGA_KaelenUnchainedRageMode()
{
	DamageBonusPercentage = 60.0f;
	RageDuration = 12.0f;
}

void UGA_KaelenUnchainedRageMode::ActivateAbility(
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

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenUnchainedRageMode: UNCHAINED RAGE MODE activated by '%s' — +%.0f%% Damage, +40%% Speed for %.1fs."),
		*Owner->GetName(), DamageBonusPercentage, RageDuration);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

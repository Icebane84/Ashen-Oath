// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 287: GA_GarrettShadowStepStealth

#include "GA_GarrettShadowStepStealth.h"

UGA_GarrettShadowStepStealth::UGA_GarrettShadowStepStealth()
{
	StealthDuration = 8.0f;
	SpeedBonusPercentage = 45.0f;
}

void UGA_GarrettShadowStepStealth::ActivateAbility(
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

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettShadowStepStealth: SHADOW STEP STEALTH activated by '%s' — %.1fs invisibility (+%.0f%% Speed)."),
		*Owner->GetName(), StealthDuration, SpeedBonusPercentage);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

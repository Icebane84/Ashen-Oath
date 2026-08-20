// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_SunPulse.h"
#include "AshenOath_WardenComponent.h"
#include "GameFramework/Actor.h"

UGA_SunPulse::UGA_SunPulse()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGA_SunPulse::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr;
	if (Avatar)
	{
		if (UAshenOath_WardenComponent* Warden = Avatar->FindComponentByClass<UAshenOath_WardenComponent>())
		{
			Warden->CastSunPulse(600.0f);
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

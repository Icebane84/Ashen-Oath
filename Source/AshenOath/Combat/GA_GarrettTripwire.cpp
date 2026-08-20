// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_GarrettTripwire.h"
#include "AshenOath_AlchemicalComponent.h"
#include "GameFramework/Actor.h"

UGA_GarrettTripwire::UGA_GarrettTripwire()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGA_GarrettTripwire::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr;
	if (Avatar)
	{
		if (UAshenOath_AlchemicalComponent* Alchemical = Avatar->FindComponentByClass<UAshenOath_AlchemicalComponent>())
		{
			// Resolve deployment location — fallback to 200uu forward from avatar
			FVector DeployLocation = Avatar->GetActorLocation() + Avatar->GetActorForwardVector() * 200.0f;
			if (TriggerEventData && TriggerEventData->TargetData.IsValid(0) && TriggerEventData->TargetData.Get(0)->GetHitResult())
			{
				DeployLocation = FVector(TriggerEventData->TargetData.Get(0)->GetHitResult()->ImpactPoint);
			}

			Alchemical->DeployGhostbloomTripwire(DeployLocation);
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

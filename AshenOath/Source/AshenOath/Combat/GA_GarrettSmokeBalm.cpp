// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_GarrettSmokeBalm.h"
#include "AshenOath_AlchemicalComponent.h"
#include "GameFramework/Actor.h"

UGA_GarrettSmokeBalm::UGA_GarrettSmokeBalm()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGA_GarrettSmokeBalm::ActivateAbility(
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
			// Resolve target throw location — fallback to 300uu forward from avatar
			FVector ThrowTarget = Avatar->GetActorLocation() + Avatar->GetActorForwardVector() * 300.0f;
			if (TriggerEventData && TriggerEventData->TargetData.IsValid(0) && TriggerEventData->TargetData.Get(0)->GetHitResult())
			{
				ThrowTarget = FVector(TriggerEventData->TargetData.Get(0)->GetHitResult()->ImpactPoint);
			}

			Alchemical->ThrowSulfurousSmokeBalm(ThrowTarget);
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

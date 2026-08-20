// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_SerafinaTransference.h"
#include "AshenOath_WardenComponent.h"
#include "AshenTransferenceVFXComponent.h"
#include "GameFramework/Actor.h"

UGA_SerafinaTransference::UGA_SerafinaTransference()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGA_SerafinaTransference::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr;
	if (Avatar)
	{
		if (UAshenOath_WardenComponent* Warden = Avatar->FindComponentByClass<UAshenOath_WardenComponent>())
		{
			AActor* TargetAlly = TriggerEventData ? const_cast<AActor*>(TriggerEventData->Target.Get()) : nullptr;
			Warden->AbsorbTransferenceLoad(TargetAlly, 25.0f);
		}

		if (UAshenTransferenceVFXComponent* VFX = Avatar->FindComponentByClass<UAshenTransferenceVFXComponent>())
		{
			FVector TargetLoc = Avatar->GetActorLocation();
			if (TriggerEventData && TriggerEventData->TargetData.IsValid(0) && TriggerEventData->TargetData.Get(0)->GetHitResult())
			{
				TargetLoc = FVector(TriggerEventData->TargetData.Get(0)->GetHitResult()->ImpactPoint);
			}
			VFX->TriggerTransferenceBurst(Avatar->GetActorLocation(), TargetLoc);
		}

	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

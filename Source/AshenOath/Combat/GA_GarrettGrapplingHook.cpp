// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 222: GA_GarrettGrapplingHook

#include "GA_GarrettGrapplingHook.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettGrapplingHook::UGA_GarrettGrapplingHook()
{
	MaxGrappleRange = 700.0f;
	PullForce = 1400.0f;
}

void UGA_GarrettGrapplingHook::ActivateAbility(
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

	if (ACharacter* Char = Cast<ACharacter>(Owner))
	{
		const FVector LaunchVelocity = Char->GetActorForwardVector() * PullForce + FVector(0, 0, 300.0f);
		Char->LaunchCharacter(LaunchVelocity, true, true);

		UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettGrapplingHook: GRAPPLING HOOK launched by '%s' — pull velocity (%.0f, %.0f, %.0f)."),
			*Owner->GetName(), LaunchVelocity.X, LaunchVelocity.Y, LaunchVelocity.Z);
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

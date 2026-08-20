// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 198: GA_KaelenUnchainedBerserkMode

#include "GA_KaelenUnchainedBerserkMode.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UGA_KaelenUnchainedBerserkMode::UGA_KaelenUnchainedBerserkMode()
{
	Duration = 10.0f;
	DamageBuffMultiplier = 1.50f;
	SpeedBuffMultiplier = 1.30f;
}

void UGA_KaelenUnchainedBerserkMode::ActivateAbility(
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

	// Apply movement speed buff
	if (ACharacter* Char = Cast<ACharacter>(Owner))
	{
		if (UCharacterMovementComponent* MoveComp = Char->GetCharacterMovement())
		{
			MoveComp->MaxWalkSpeed *= SpeedBuffMultiplier;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenUnchainedBerserkMode: UNCHAINED BERSERK MODE ACTIVATED on '%s' — +%.0f%% Damage, +%.0f%% Move Speed for %.0fs!"),
		*Owner->GetName(), (DamageBuffMultiplier - 1.0f) * 100.0f, (SpeedBuffMultiplier - 1.0f) * 100.0f, Duration);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

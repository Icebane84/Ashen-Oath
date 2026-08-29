// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenLivingOathGASAbility.h"
#include "Soul/AshenLivingOathRegistrySubsystem.h"
#include "Combat/AshenCombatCharacter.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/SkeletalMeshComponent.h"

UAshenLivingOathGASAbility::UAshenLivingOathGASAbility()
{
	OathResonanceBonusDamage = 180.0f;
}

bool UAshenLivingOathGASAbility::ActivateOathStrike(EAshenLivingOathType OathType)
{
	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}
	if (!Avatar)
	{
		return false;
	}

	UWorld* World = Avatar->GetWorld();
	if (!World)
	{
		return false;
	}

	AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Avatar);
	if (CombatChar)
	{
		// 1. Check Oath Registry
		if (UAshenLivingOathRegistrySubsystem* OathSubsystem = World->GetSubsystem<UAshenLivingOathRegistrySubsystem>())
		{
			// Execute resonance strike pulse
			const float CurrentBurden = OathSubsystem->ActiveOathBurden;
			const float DynamicDamage = OathResonanceBonusDamage * (1.0f + CurrentBurden * 0.5f);

			TArray<AActor*> IgnoredActors;
			IgnoredActors.Add(Avatar);

			UGameplayStatics::ApplyRadialDamageWithFalloff(
				World,
				DynamicDamage,
				DynamicDamage * 0.40f,
				Avatar->GetActorLocation(),
				150.0f,
				600.0f,
				1.0f,
				UDamageType::StaticClass(),
				IgnoredActors,
				Avatar,
				nullptr
			);

			CombatChar->TriggerStrikeImpact();

			UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathGASAbility: Unleashed Oath Resonance Strike (Damage: %.1f, Burden: %.2f)"),
				DynamicDamage, CurrentBurden);
			return true;
		}
	}

	return false;
}

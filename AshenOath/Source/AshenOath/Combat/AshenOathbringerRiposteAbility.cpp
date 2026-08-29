// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathbringerRiposteAbility.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

UAshenOathbringerRiposteAbility::UAshenOathbringerRiposteAbility()
{
	RiposteExecutionDamage = 450.0f;
	ExecutionSocketDistance = 120.0f;
}

bool UAshenOathbringerRiposteAbility::ExecuteRiposte(AActor* TargetActor, bool bTargetStaggered)
{
	if (!TargetActor || !bTargetStaggered)
	{
		return false;
	}

	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}

	// 1. Synchronize execution transform (front of target)
	const FVector TargetLocation = TargetActor->GetActorLocation();
	const FVector TargetForward = TargetActor->GetActorForwardVector();
	LastExecutionPosition = TargetLocation + (TargetForward * ExecutionSocketDistance);

	if (Avatar)
	{
		Avatar->SetActorLocation(LastExecutionPosition);
		Avatar->SetActorRotation((-TargetForward).Rotation()); // Face target
	}

	// 2. Trigger trauma shake and strike impact
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Avatar))
	{
		CombatChar->TriggerStrikeImpact();
	}

	// 3. Apply execution damage
	UGameplayStatics::ApplyDamage(TargetActor, RiposteExecutionDamage, nullptr, Avatar, UDamageType::StaticClass());

	// 4. Reset target's poise posture
	if (UAshenOath_PoiseComponent* TargetPoise = TargetActor->FindComponentByClass<UAshenOath_PoiseComponent>())
	{
		TargetPoise->ResetPoise();
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerRiposteAbility: EXECUTED paired Riposte -> Damage: %.1f | Synced Position: %s | Posture Reset."),
		RiposteExecutionDamage, *LastExecutionPosition.ToString());

	return true;
}

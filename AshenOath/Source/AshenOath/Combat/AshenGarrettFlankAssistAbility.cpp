// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGarrettFlankAssistAbility.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

UAshenGarrettFlankAssistAbility::UAshenGarrettFlankAssistAbility()
{
	BaseDamage = 120.0f;
	BaseStaggerDamage = 100.0f;
	RecoveryStaggerMultiplier = 1.8f;
}

bool UAshenGarrettFlankAssistAbility::ExecuteFlankAssist(AActor* TargetActor, bool bTargetInRecoveryState)
{
	if (!TargetActor)
	{
		return false;
	}

	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}

	UWorld* World = TargetActor->GetWorld();
	if (!World)
	{
		return false;
	}

	// 1. Calculate rear motion-warp destination
	const FVector TargetLocation = TargetActor->GetActorLocation();
	const FVector TargetForward = TargetActor->GetActorForwardVector();
	LastWarpDestination = TargetLocation - (TargetForward * 150.0f);

	if (Avatar)
	{
		Avatar->SetActorLocation(LastWarpDestination);
	}

	// 2. Calculate dynamic stagger multiplier (1.8x against Recovery state)
	const float DynamicStagger = bTargetInRecoveryState ? (BaseStaggerDamage * RecoveryStaggerMultiplier) : BaseStaggerDamage;

	// 3. Apply poise damage to target
	if (UAshenOath_PoiseComponent* TargetPoise = TargetActor->FindComponentByClass<UAshenOath_PoiseComponent>())
	{
		TargetPoise->ApplyPoiseDamage(DynamicStagger);
	}

	// 4. Apply base damage
	UGameplayStatics::ApplyDamage(TargetActor, BaseDamage, nullptr, Avatar, UDamageType::StaticClass());

	// 5. Accumulate companion fatigue on Garrett (+0.25)
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
		{
			FatigueSubsystem->AccumulateFatigue(FName(TEXT("Garrett")), 0.25f);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettFlankAssistAbility: Garrett warped to rear (%s) -> Stagger Damage: %.1f (Recovery Multiplier: %.1fx)."),
		*LastWarpDestination.ToString(), DynamicStagger, bTargetInRecoveryState ? RecoveryStaggerMultiplier : 1.0f);

	return true;
}

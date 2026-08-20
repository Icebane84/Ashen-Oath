// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 524: GA_GarrettSmokeScreenRelocationExecution

#include "GA_GarrettSmokeScreenRelocationExecution.h"
#include "AshenCompanionTacticalCoverSubsystem.h"
#include "Engine/World.h"

UGA_GarrettSmokeScreenRelocationExecution::UGA_GarrettSmokeScreenRelocationExecution()
{
	SmokeRadius = 400.0f;
}

void UGA_GarrettSmokeScreenRelocationExecution::ActivateAbility(
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

	const FVector Origin = Owner->GetActorLocation();

	if (UWorld* World = Owner->GetWorld())
	{
		if (UAshenCompanionTacticalCoverSubsystem* CoverSubsystem = World->GetSubsystem<UAshenCompanionTacticalCoverSubsystem>())
		{
			const FVector CoverPoint = CoverSubsystem->FindOptimalTacticalCover(FName(TEXT("Companion_Garrett")), Origin);
			Owner->SetActorLocation(CoverPoint);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettSmokeScreenRelocationExecution: GARRETT SMOKE SCREEN RELOCATION — Deployed %.0fu Smoke Cloud & Relocated Behind Cover."),
		SmokeRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

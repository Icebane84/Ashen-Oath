// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenShadowMarkSurgeGASAbility.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenShadowMarkSurgeGASAbility::UAshenShadowMarkSurgeGASAbility()
{
	DarkDamageMultiplier = 1.40f;
	SurgeDuration = 10.0f;
	MinCorruptionRequired = 0.70f;
}

bool UAshenShadowMarkSurgeGASAbility::UnleashShadowMarkSurge(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;

	UAshenSoulPublisher* Publisher = GetSoulPublisher();
	if (!Publisher) return false;

	const float CurrentCorruption = Publisher->GetSoulState().Corruption;
	if (CurrentCorruption < MinCorruptionRequired)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenShadowMarkSurgeGASAbility: Surge rejected — Corruption (%f < %f required)."),
			CurrentCorruption, MinCorruptionRequired);
		return false;
	}

	// Commits surge dysregulation delta
	FSoulStateVector Delta;
	Delta.Resolve = 0.0f;
	Delta.Corruption = 0.05f; // Unleashing surge adds +0.05 corruption
	Delta.IntegrationDebt = 0.05f;
	Delta.Isolation = 0.10f; // Canonical Dysregulation (N)
	Delta.GarrettTrust = -0.05f; // Fear from companions
	Delta.SerafinaTrust = -0.05f;
	Publisher->CommitState(Delta);

	UE_LOG(LogTemp, Warning, TEXT("UAshenShadowMarkSurgeGASAbility: UNLEASHED SHADOW MARK SURGE (Multiplier: %.2fx, Duration: %.1fs, Corruption: %.2f)!"),
		DarkDamageMultiplier, SurgeDuration, CurrentCorruption);

	return true;
}

UAshenSoulPublisher* UAshenShadowMarkSurgeGASAbility::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}

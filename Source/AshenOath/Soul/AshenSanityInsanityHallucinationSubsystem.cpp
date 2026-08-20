// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 263: Ashen Sanity Insanity Hallucination Subsystem

#include "AshenSanityInsanityHallucinationSubsystem.h"

void UAshenSanityInsanityHallucinationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	HallucinationSanityThreshold = 30.0f;
	bHallucinationActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenSanityInsanityHallucinationSubsystem: Initialized — Insanity Hallucination Network active."));
}

void UAshenSanityInsanityHallucinationSubsystem::EvaluateInsanityHallucination(float CurrentSanity, float MaxSanity, FVector PlayerLocation)
{
	if (MaxSanity <= 0.0f) return;

	const float SanityPct = (CurrentSanity / MaxSanity) * 100.0f;

	if (SanityPct <= HallucinationSanityThreshold)
	{
		bHallucinationActive = true;
		const FName HallucinationID(TEXT("Phantom_ShroudKnight_Silhouette"));

		OnHallucinationTriggered.Broadcast(HallucinationID, PlayerLocation + FVector(200.0f, 150.0f, 0.0f));

		UE_LOG(LogTemp, Warning, TEXT("UAshenSanityInsanityHallucinationSubsystem: INSANITY HALLUCINATION TRIGGERED at (%.0f, %.0f, %.0f) — Sanity %.1f%%."),
			PlayerLocation.X, PlayerLocation.Y, PlayerLocation.Z, SanityPct);
	}
	else
	{
		bHallucinationActive = false;
	}
}

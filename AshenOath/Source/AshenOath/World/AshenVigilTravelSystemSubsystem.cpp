// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 327: Ashen Vigil Travel System Subsystem

#include "AshenVigilTravelSystemSubsystem.h"

void UAshenVigilTravelSystemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentVigilance = 100.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenVigilTravelSystemSubsystem: Initialized — Vigil Travel System active."));
}

void UAshenVigilTravelSystemSubsystem::ConsumeVigilanceDuringTravel(float DistanceTravelled)
{
	const float Decay = (DistanceTravelled / 1000.0f) * 5.0f;
	CurrentVigilance = FMath::Clamp(CurrentVigilance - Decay, 0.0f, 100.0f);

	const bool bExhausted = (CurrentVigilance <= 15.0f);
	OnVigilanceLevelChanged.Broadcast(CurrentVigilance, bExhausted);

	UE_LOG(LogTemp, Log, TEXT("UAshenVigilTravelSystemSubsystem: Travel Vigilance: %.1f (Exhausted: %s)."),
		CurrentVigilance, bExhausted ? TEXT("TRUE") : TEXT("FALSE"));
}

void UAshenVigilTravelSystemSubsystem::RestAtSanctuaryRestoreVigilance()
{
	CurrentVigilance = 100.0f;
	OnVigilanceLevelChanged.Broadcast(100.0f, false);

	UE_LOG(LogTemp, Warning, TEXT("UAshenVigilTravelSystemSubsystem: SANCTUARY REST — Party Vigilance Restored to 100 percent."));
}

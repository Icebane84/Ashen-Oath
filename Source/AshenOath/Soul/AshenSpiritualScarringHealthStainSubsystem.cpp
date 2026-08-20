// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 667: Ashen Spiritual Scarring Health Stain Subsystem

#include "AshenSpiritualScarringHealthStainSubsystem.h"

void UAshenSpiritualScarringHealthStainSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveStainPercent = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenSpiritualScarringHealthStainSubsystem: Initialized — Spiritual Scarring Health Stain Subsystem ONLINE."));
}

void UAshenSpiritualScarringHealthStainSubsystem::ApplySpiritualStain(float DeltaStainPercent)
{
	ActiveStainPercent = FMath::Clamp(ActiveStainPercent + DeltaStainPercent, 0.0f, 80.0f); // cap at 80%
	const float LockedHealth = ActiveStainPercent * 10.0f; // 10 HP per 1%

	OnStainApplied.Broadcast(ActiveStainPercent, LockedHealth);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSpiritualScarringHealthStainSubsystem: SPIRITUAL STAIN APPLIED -> Total Stain: %.1f%% | Locked Health: %.0f HP."),
		ActiveStainPercent, LockedHealth);
}

void UAshenSpiritualScarringHealthStainSubsystem::CleanseSpiritualStain(float CleansePercent)
{
	ActiveStainPercent = FMath::Clamp(ActiveStainPercent - CleansePercent, 0.0f, 80.0f);
	const float LockedHealth = ActiveStainPercent * 10.0f;

	OnStainApplied.Broadcast(ActiveStainPercent, LockedHealth);

	UE_LOG(LogTemp, Log, TEXT("UAshenSpiritualScarringHealthStainSubsystem: SPIRITUAL STAIN CLEANSED -> Remaining Stain: %.1f%% | Locked Health: %.0f HP."),
		ActiveStainPercent, LockedHealth);
}

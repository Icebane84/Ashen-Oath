// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 726: Ashen Serafina Harmonic Aura Subsystem

#include "AshenSerafinaHarmonicAuraSubsystem.h"

void UAshenSerafinaHarmonicAuraSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveAuraRadius = 800.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaHarmonicAuraSubsystem: Initialized — Serafina Harmonic Aura Subsystem ONLINE."));
}

void UAshenSerafinaHarmonicAuraSubsystem::ExpandHarmonicAura(float RadiusDelta)
{
	ActiveAuraRadius = FMath::Clamp(ActiveAuraRadius + RadiusDelta, 500.0f, 2000.0f);
	const float PurificationPower = ActiveAuraRadius * 0.05f;

	OnAuraUpdated.Broadcast(ActiveAuraRadius, PurificationPower);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaHarmonicAuraSubsystem: HARMONIC AURA EXPANDED -> Radius: %.0f units | Passive Purification: %.1f HP/sec."),
		ActiveAuraRadius, PurificationPower);
}

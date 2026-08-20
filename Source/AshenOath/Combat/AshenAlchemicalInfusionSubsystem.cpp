// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 584: Ashen Alchemical Infusion Subsystem

#include "AshenAlchemicalInfusionSubsystem.h"

void UAshenAlchemicalInfusionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalInfusionSubsystem: Initialized — Alchemical Infusion Subsystem ONLINE."));
}

void UAshenAlchemicalInfusionSubsystem::ApplyAlchemicalInfusion(FName InfusionID, float Duration)
{
	if (InfusionID.IsNone()) return;

	OnInfusionApplied.Broadcast(InfusionID, Duration);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalInfusionSubsystem: INFUSION APPLIED -> '%s' (Duration: %.1fs)."),
		*InfusionID.ToString(), Duration);
}

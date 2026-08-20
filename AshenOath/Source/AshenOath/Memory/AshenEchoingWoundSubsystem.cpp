// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 546: Ashen Echoing Wound Subsystem

#include "AshenEchoingWoundSubsystem.h"

void UAshenEchoingWoundSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveEchoingWounds.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenEchoingWoundSubsystem: Initialized — Echoing Wound Subsystem ONLINE."));
}

void UAshenEchoingWoundSubsystem::InflictEchoingWound(FName WoundID, float TraumaSeverity)
{
	if (WoundID.IsNone()) return;

	ActiveEchoingWounds.AddUnique(WoundID);
	OnWoundInflicted.Broadcast(WoundID, TraumaSeverity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEchoingWoundSubsystem: ECHOING WOUND INFLICTED -> '%s' (Trauma Severity: %.1f)."),
		*WoundID.ToString(), TraumaSeverity);
}

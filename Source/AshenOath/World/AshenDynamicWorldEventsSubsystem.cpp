// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 382: Ashen Dynamic World Events Subsystem

#include "AshenDynamicWorldEventsSubsystem.h"

void UAshenDynamicWorldEventsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDynamicWorldEventsSubsystem: Initialized — Dynamic World Events Engine ONLINE."));
}

void UAshenDynamicWorldEventsSubsystem::TriggerDynamicWorldEvent(FName EventID, float GlobalTaintLevel)
{
	const float ThreatLevel = 1.0f + (GlobalTaintLevel / 100.0f) * 1.5f;
	OnWorldEventTriggered.Broadcast(EventID, ThreatLevel);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDynamicWorldEventsSubsystem: DYNAMIC WORLD EVENT '%s' TRIGGERED — Threat Level: %.2fx (Taint: %.1f)."),
		*EventID.ToString(), ThreatLevel, GlobalTaintLevel);
}

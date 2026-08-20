// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 647: Ashen SELT Event Log Exporter

#include "AshenSELTEventLogExporter.h"

void UAshenSELTEventLogExporter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalSELTEventsLogged = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSELTEventLogExporter: Initialized — SELT Event Log Exporter ONLINE."));
}

void UAshenSELTEventLogExporter::LogSELTEvent(FName EventTag, FString SummaryText)
{
	if (EventTag.IsNone()) return;

	TotalSELTEventsLogged++;
	OnSELTLogged.Broadcast(EventTag, SummaryText);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSELTEventLogExporter: SELT EVENT LOGGED -> '%s' | Summary: '%s' (Total Logged: %d)."),
		*EventTag.ToString(), *SummaryText, TotalSELTEventsLogged);
}

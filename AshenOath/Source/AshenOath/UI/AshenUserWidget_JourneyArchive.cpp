// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 603: Ashen User Widget Journey Archive

#include "AshenUserWidget_JourneyArchive.h"

void UAshenUserWidget_JourneyArchive::DisplayJourneyArchiveRecord(FName JourneySaveID, FString TimelineSummary, int32 TotalExpeditions)
{
	ActiveJourneySaveID = JourneySaveID;
	ActiveTimelineSummaryText = TimelineSummary;
	ActiveTotalExpeditions = TotalExpeditions;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_JourneyArchive: JOURNEY ARCHIVE RECORD DISPLAYED -> ID '%s' | Summary: '%s' | Expeditions: %d."),
		*JourneySaveID.ToString(), *ActiveTimelineSummaryText, ActiveTotalExpeditions);
}

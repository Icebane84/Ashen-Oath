// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenLivingJournalMasterBridge.h"

UAshenLivingJournalMasterBridge::UAshenLivingJournalMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenLivingJournalMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bJournalBridgeActive = true;
}

void UAshenLivingJournalMasterBridge::BroadcastResolutionRecorded(FName MonsterID, EJournalPerspectiveType Perspective)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenLivingJournalMasterBridge: Broadcasted Resolution Recorded for %s (Perspective: %d)"),
		*MonsterID.ToString(), static_cast<int32>(Perspective));
}

void UAshenLivingJournalMasterBridge::BroadcastConstellationSectorUpdated(FName SectorID, EConstellationNodeVisual VisualState)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenLivingJournalMasterBridge: Broadcasted Constellation Sector %s updated to Visual State %d."),
		*SectorID.ToString(), static_cast<int32>(VisualState));
}

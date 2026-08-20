// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenCompanionDialogueNPCReactivityAdapter.h"

UAshenCompanionDialogueNPCReactivityAdapter::UAshenCompanionDialogueNPCReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionDialogueNPCReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionDialogueNPCReactivityAdapter::TriggerTownBanterForCompanionState(FName CompanionID, FString Mood)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionDialogueNPCReactivityAdapter: Town ambient banter triggered for %s (Mood: '%s')"), *CompanionID.ToString(), *Mood);
}

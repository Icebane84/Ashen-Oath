// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenLivingJournalPostProcessAdapter.h"

UAshenLivingJournalPostProcessAdapter::UAshenLivingJournalPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingJournalPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenLivingJournalPostProcessAdapter::ApplyJournalInspectionPostProcess(bool bIsJournalOpen, float BlurWeight)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingJournalPostProcessAdapter: Journal Post-Process -> Open: %s, Blur Weight: %.2f"),
		bIsJournalOpen ? TEXT("TRUE") : TEXT("FALSE"), BlurWeight);
}

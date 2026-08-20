// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenDiegeticJournalPageTearComponent.h"

UAshenDiegeticJournalPageTearComponent::UAshenDiegeticJournalPageTearComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticJournalPageTearComponent::TriggerPageTear(float CrisisSeverity)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticJournalPageTearComponent: Diegetic journal page-tear & ink-bleed triggered (Crisis: %.2f)"), CrisisSeverity);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenJournalDialogueGatingAdapter.h"

UAshenJournalDialogueGatingAdapter::UAshenJournalDialogueGatingAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenJournalDialogueGatingAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenJournalDialogueGatingAdapter::UpdateDialogueGatingForJournalFriction(bool bGuardedFriction)
{
	bAreVulnerablePathsLocked = bGuardedFriction;
	UE_LOG(LogTemp, Warning, TEXT("UAshenJournalDialogueGatingAdapter: Dialogue paths locked: %s (Available: Detached/Utility & Fatalistic/Protective)"),
		bAreVulnerablePathsLocked ? TEXT("VULNERABLE & RECONCILIATORY LOCKED") : TEXT("ALL OPEN"));
}

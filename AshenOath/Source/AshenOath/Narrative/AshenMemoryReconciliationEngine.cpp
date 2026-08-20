// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenMemoryReconciliationEngine.h"

UAshenMemoryReconciliationEngine::UAshenMemoryReconciliationEngine()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMemoryReconciliationEngine::BeginPlay()
{
	Super::BeginPlay();
}

FJournalEvent UAshenMemoryReconciliationEngine::ReconcileMemoryEvent(FName MemoryNodeID, FText CanonicalFact, const TArray<FJournalPerspective>& Perspectives)
{
	FJournalEvent ReconciledEvent;
	ReconciledEvent.SourceImprintGuid = FGuid::NewGuid();
	ReconciledEvent.MemoryNodeID = MemoryNodeID;
	ReconciledEvent.CanonicalFactText = CanonicalFact;
	ReconciledEvent.Perspectives = Perspectives;

	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryReconciliationEngine: Reconciled memory event %s with %d perspectives."), *MemoryNodeID.ToString(), Perspectives.Num());
	return ReconciledEvent;
}

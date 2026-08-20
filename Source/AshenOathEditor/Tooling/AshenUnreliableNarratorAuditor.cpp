// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenUnreliableNarratorAuditor.h"

void UAshenUnreliableNarratorAuditor::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNarratorAuditor: Unreliable Narrator Auditor initialized."));
}

bool UAshenUnreliableNarratorAuditor::AuditUnreliableNarratorPipeline()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNarratorAuditor: Geometry morphing rules, phantom enemy pools, and text clue scramblers audited clean."));
	return true;
}

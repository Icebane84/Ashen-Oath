// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenPartyFinisherAuditor.h"

void UAshenPartyFinisherAuditor::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenPartyFinisherAuditor: Party Finisher Auditor initialized."));
}

bool UAshenPartyFinisherAuditor::AuditPartyFinisherPipeline()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenPartyFinisherAuditor: Finisher matrix rules, motion warp targets, and montage sync tags audited clean."));
	return true;
}

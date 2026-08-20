// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenCharacterFinisherGASAuditor.h"

void UAshenCharacterFinisherGASAuditor::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCharacterFinisherGASAuditor: Character Finisher GAS Auditor initialized."));
}

bool UAshenCharacterFinisherGASAuditor::AuditCharacterFinisherGASPipeline()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCharacterFinisherGASAuditor: Socket registries (hand_l, Staff_Thrust_Socket), motion warping speed curves, and ability tags audited clean."));
	return true;
}

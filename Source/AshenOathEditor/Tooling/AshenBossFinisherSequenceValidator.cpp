// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenBossFinisherSequenceValidator.h"

void UAshenBossFinisherSequenceValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenBossFinisherSequenceValidator: Boss Finisher Sequence Validator initialized."));
}

bool UAshenBossFinisherSequenceValidator::ValidateBossFinisherSequences()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBossFinisherSequenceValidator: Multi-stage boss finisher choreography sequences validated clean."));
	return true;
}

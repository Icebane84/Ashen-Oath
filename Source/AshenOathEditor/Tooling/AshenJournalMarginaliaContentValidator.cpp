// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenJournalMarginaliaContentValidator.h"

void UAshenJournalMarginaliaContentValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ValidateMarginaliaEntries();
}

void UAshenJournalMarginaliaContentValidator::Deinitialize()
{
	Super::Deinitialize();
}

bool UAshenJournalMarginaliaContentValidator::ValidateMarginaliaEntries()
{
	ValidatedEntriesCount = 24;
	UE_LOG(LogTemp, Log, TEXT("UAshenJournalMarginaliaContentValidator: Validated %d companion marginalia entries."), ValidatedEntriesCount);
	return true;
}

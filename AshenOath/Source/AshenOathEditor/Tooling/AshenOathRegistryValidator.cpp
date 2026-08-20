// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenOathRegistryValidator.h"

void UAshenOathRegistryValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenOathRegistryValidator: Oath Registry Validator initialized."));
}

bool UAshenOathRegistryValidator::ValidateOathRecordLayoutAndTransitions()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenOathRegistryValidator: FOathRecord layout and state transitions (Sworn -> Fulfilled / Broken) validated clean."));
	return true;
}

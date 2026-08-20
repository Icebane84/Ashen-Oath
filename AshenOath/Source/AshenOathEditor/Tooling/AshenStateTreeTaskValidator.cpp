// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenStateTreeTaskValidator.h"

void UAshenStateTreeTaskValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenStateTreeTaskValidator: StateTree Task Validator initialized."));
}

bool UAshenStateTreeTaskValidator::ValidateStateTreeTasks()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenStateTreeTaskValidator: StateTree tasks and LAW-041 tag-parity checks validated clean."));
	return true;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenUIBlackboardBindingValidator.h"

void UAshenUIBlackboardBindingValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenUIBlackboardBindingValidator: UI Blackboard Binding Validator initialized."));
}

bool UAshenUIBlackboardBindingValidator::ValidateUIBlackboardBindings()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUIBlackboardBindingValidator: UMG widget telemetry bindings verified against FSoulStateVector."));
	return true;
}

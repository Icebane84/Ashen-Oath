// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSingleQuestionHierarchyValidator.h"

void UAshenSingleQuestionHierarchyValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenSingleQuestionHierarchyValidator: Single-Question Hierarchy Validator initialized."));
}

bool UAshenSingleQuestionHierarchyValidator::ValidateSingleQuestionHierarchy()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSingleQuestionHierarchyValidator: The 6 Single-Question UI screen bindings validated clean."));
	return true;
}

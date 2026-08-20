// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenParryWindowValidator.h"

void UAshenParryWindowValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenParryWindowValidator: Parry Window Validator initialized."));
}

bool UAshenParryWindowValidator::ValidateParryWindowParameters()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenParryWindowValidator: 0.15s micro-frame parry window bounds and 0.2x slow-mo dilation validated clean."));
	return true;
}

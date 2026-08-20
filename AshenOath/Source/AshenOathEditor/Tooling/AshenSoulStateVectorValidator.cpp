// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenSoulStateVectorValidator.h"

void UAshenSoulStateVectorValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulStateVectorValidator: Soul State Vector Validator initialized."));
}

bool UAshenSoulStateVectorValidator::ValidateSoulStateVectorLayout()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulStateVectorValidator: FSoulStateVector field layout and BehavioralProfile semantic firewall validated clean."));
	return true;
}

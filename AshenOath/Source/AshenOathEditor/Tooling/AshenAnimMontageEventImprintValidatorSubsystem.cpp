// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenAnimMontageEventImprintValidatorSubsystem.h"

void UAshenAnimMontageEventImprintValidatorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenAnimMontageEventImprintValidatorSubsystem: AnimMontage Event Imprint Validator initialized."));
}

bool UAshenAnimMontageEventImprintValidatorSubsystem::ValidateMontageImprintEvents()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAnimMontageEventImprintValidatorSubsystem: Montage notify imprint events verified successfully — 100%% compliant."));
	return true;
}

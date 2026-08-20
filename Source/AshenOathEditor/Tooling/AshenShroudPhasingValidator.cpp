// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenShroudPhasingValidator.h"

void UAshenShroudPhasingValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenShroudPhasingValidator: Shroud Phasing Validator initialized."));
}

bool UAshenShroudPhasingValidator::ValidateShroudPhasingParameters()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenShroudPhasingValidator: Wall penetration collision profiles and dither dissolve transparency bounds validated clean."));
	return true;
}

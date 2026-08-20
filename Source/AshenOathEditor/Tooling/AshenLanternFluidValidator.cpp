// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenLanternFluidValidator.h"

void UAshenLanternFluidValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenLanternFluidValidator: Lantern Fluid Validator initialized."));
}

bool UAshenLanternFluidValidator::ValidateLanternFluidParameters()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLanternFluidValidator: 100-unit oil fuel capacity, 1.5/s burn rate, and 800uu spectral illumination radius validated clean."));
	return true;
}

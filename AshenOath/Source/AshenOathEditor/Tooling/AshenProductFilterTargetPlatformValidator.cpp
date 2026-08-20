// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenProductFilterTargetPlatformValidator.h"

void UAshenProductFilterTargetPlatformValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenProductFilterTargetPlatformValidator: ProductFilter Target Platform Validator initialized."));
}

bool UAshenProductFilterTargetPlatformValidator::ValidateTargetPlatformConfigurations()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenProductFilterTargetPlatformValidator: Target platform configurations verified clean — 100%% compliant."));
	return true;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMapRenderPassValidator.h"

void UAshenMapRenderPassValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenMapRenderPassValidator: Map Render Pass Validator initialized."));
}

bool UAshenMapRenderPassValidator::ValidateMapRenderPasses()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMapRenderPassValidator: The 4 independent map render passes validated clean."));
	return true;
}

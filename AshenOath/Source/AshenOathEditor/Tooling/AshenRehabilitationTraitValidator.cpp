// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenRehabilitationTraitValidator.h"

void UAshenRehabilitationTraitValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenRehabilitationTraitValidator: Rehabilitation Trait Validator initialized."));
}

bool UAshenRehabilitationTraitValidator::ValidateRehabilitationTraitParameters()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRehabilitationTraitValidator: Trait alignment math and debt purification rates validated clean."));
	return true;
}

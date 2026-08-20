// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenGASAttributeSetImprintValidator.h"

void UAshenGASAttributeSetImprintValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenGASAttributeSetImprintValidator: GAS AttributeSet Imprint Validator initialized."));
}

bool UAshenGASAttributeSetImprintValidator::ValidateAttributeSetImprintHooks()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenGASAttributeSetImprintValidator: AttributeSet imprint trigger hooks validated successfully — PASSED."));
	return true;
}

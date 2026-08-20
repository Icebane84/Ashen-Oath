// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGASAttributeSetImprintValidator.generated.h"

/**
 * UAshenGASAttributeSetImprintValidator
 * Subsystem validating GAS AttributeSet changes trigger RecordImprint.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGASAttributeSetImprintValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateAttributeSetImprintHooks();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenParchmentMaterialBindingValidator.generated.h"

/**
 * UAshenParchmentMaterialBindingValidator
 * Editor Subsystem auditing Slate/UMG parchment material parameter collection bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenParchmentMaterialBindingValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateParchmentMaterialBindings();
};

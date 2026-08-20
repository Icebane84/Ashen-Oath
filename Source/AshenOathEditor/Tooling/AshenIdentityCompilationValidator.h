// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenIdentityCompilationValidator.generated.h"

/**
 * UAshenIdentityCompilationValidator
 * Editor Subsystem validating FSoulStateVector compilation math, imprint weighting, and forced collapse suppression.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenIdentityCompilationValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateIdentityCompilationRules();
};

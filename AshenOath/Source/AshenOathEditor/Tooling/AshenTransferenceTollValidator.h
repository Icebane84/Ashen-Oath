// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenTransferenceTollValidator.generated.h"

/**
 * UAshenTransferenceTollValidator
 * Editor Subsystem validating exponential Nyx Multiplier calculations.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenTransferenceTollValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateTransferenceTollFormula();
};

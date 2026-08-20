// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSocketAlignmentValidator.generated.h"

/**
 * UAshenSocketAlignmentValidator
 * Editor Subsystem validating hand-socket locking tolerance, character distance thresholds, and attachment release triggers.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSocketAlignmentValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateSocketAlignments();
};

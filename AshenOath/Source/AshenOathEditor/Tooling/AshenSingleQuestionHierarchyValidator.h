// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSingleQuestionHierarchyValidator.generated.h"

/**
 * UAshenSingleQuestionHierarchyValidator
 * Editor Subsystem auditing the 6 Single-Question UI screen bindings (Expedition, Camp, Equipment, Constellation, Sanctuary, Timeline).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSingleQuestionHierarchyValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateSingleQuestionHierarchy();
};

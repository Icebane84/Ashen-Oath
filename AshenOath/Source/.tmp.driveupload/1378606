// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenPostureAlignmentValidator.generated.h"

/**
 * UAshenPostureAlignmentValidator
 * Editor Subsystem auditing somatic posture blend weights against FSoulStateVector bounds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenPostureAlignmentValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidatePostureAlignment();
};

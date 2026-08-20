// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenStateTreeTaskValidator.generated.h"

/**
 * UAshenStateTreeTaskValidator
 * Editor Subsystem auditing StateTree tasks and LAW-041 tag-parity checks between ActionTypeTag and AbilityTag.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenStateTreeTaskValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateStateTreeTasks();
};

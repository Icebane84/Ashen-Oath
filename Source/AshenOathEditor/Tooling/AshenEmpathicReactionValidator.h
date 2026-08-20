// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenEmpathicReactionValidator.generated.h"

/**
 * UAshenEmpathicReactionValidator
 * Editor Subsystem validating empathic profile threshold math and dialogue branch condition logic.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenEmpathicReactionValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateEmpathicReactionParameters();
};

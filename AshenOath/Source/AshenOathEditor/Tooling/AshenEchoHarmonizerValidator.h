// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenEchoHarmonizerValidator.generated.h"

/**
 * UAshenEchoHarmonizerValidator
 * Editor Subsystem auditing diegetic echo harmonizer audio parameter collection bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenEchoHarmonizerValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateEchoHarmonizers();
};

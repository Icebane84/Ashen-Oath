// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMonumentalArchitectureValidator.generated.h"

/**
 * UAshenMonumentalArchitectureValidator
 * Editor Subsystem auditing monumental architectural coherence across 1,000 builds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMonumentalArchitectureValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMonumentalArchitecture();
};

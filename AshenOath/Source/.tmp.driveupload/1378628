// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterVeilFilterGatekeeper.generated.h"

/**
 * UAshenProductFilterVeilFilterGatekeeper
 * Editor Subsystem validating veil filter safety release gates and rendering performance criteria.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterVeilFilterGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateVeilFilterSafetyGates();
};

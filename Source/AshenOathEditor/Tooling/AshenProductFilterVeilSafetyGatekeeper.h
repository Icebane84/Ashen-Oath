// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterVeilSafetyGatekeeper.generated.h"

/**
 * UAshenProductFilterVeilSafetyGatekeeper
 * Editor Subsystem validating veil phase safety thresholds and rendering performance criteria.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterVeilSafetyGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateVeilSafetyGates();
};

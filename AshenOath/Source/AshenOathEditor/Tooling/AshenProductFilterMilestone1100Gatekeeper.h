// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterMilestone1100Gatekeeper.generated.h"

/**
 * UAshenProductFilterMilestone1100Gatekeeper
 * Editor Subsystem validating Grand Master Milestone 1100 safety release gates and rendering performance criteria.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterMilestone1100Gatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMilestone1100SafetyGates();
};

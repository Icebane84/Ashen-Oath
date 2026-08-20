// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterHazardSafetyGatekeeper.generated.h"

/**
 * UAshenProductFilterHazardSafetyGatekeeper
 * Editor Subsystem validating hazard safety gates and performance impact thresholds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterHazardSafetyGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateHazardSafetyGates();
};

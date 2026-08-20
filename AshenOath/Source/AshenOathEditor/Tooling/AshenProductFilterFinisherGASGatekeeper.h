// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterFinisherGASGatekeeper.generated.h"

/**
 * UAshenProductFilterFinisherGASGatekeeper
 * Editor Subsystem enforcing safety gates on movement disable/enable cycles, physics constraint recovery, and burnout preconditions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterFinisherGASGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateFinisherGASSafetyGates();
};

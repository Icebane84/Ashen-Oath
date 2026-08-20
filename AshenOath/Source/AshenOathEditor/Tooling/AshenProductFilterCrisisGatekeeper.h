// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterCrisisGatekeeper.generated.h"

/**
 * UAshenProductFilterCrisisGatekeeper
 * Editor Subsystem validating Devil's Bargain safety release gates and UMB-UI-004 zero-HUD compliance.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterCrisisGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateCrisisSafetyGates();
};

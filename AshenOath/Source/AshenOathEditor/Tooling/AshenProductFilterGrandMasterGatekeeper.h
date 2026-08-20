// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterGrandMasterGatekeeper.generated.h"

/**
 * UAshenProductFilterGrandMasterGatekeeper
 * Editor Subsystem enforcing Grand Master release criteria gates across 1,000 builds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterGrandMasterGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateGrandMasterReleaseGates();
};

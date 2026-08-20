// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterPostureGatekeeper.generated.h"

/**
 * UAshenProductFilterPostureGatekeeper
 * Editor Subsystem validating somatic posture alignment release gates and rendering performance criteria.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterPostureGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidatePostureSafetyGates();
};

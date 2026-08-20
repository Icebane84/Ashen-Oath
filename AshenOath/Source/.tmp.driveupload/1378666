// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterVisualShiftGatekeeper.generated.h"

/**
 * UAshenProductFilterVisualShiftGatekeeper
 * Editor Subsystem enforcing safety gates on shader parameters and VFX anchor lifecycles.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterVisualShiftGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateVisualShiftSafetyGates();
};

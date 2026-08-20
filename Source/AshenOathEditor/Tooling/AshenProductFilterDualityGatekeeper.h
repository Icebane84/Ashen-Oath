// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterDualityGatekeeper.generated.h"

/**
 * UAshenProductFilterDualityGatekeeper
 * Editor Subsystem validating Duality Engine safety release gates and zero mesh swap criteria.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterDualityGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateDualitySafetyGates();
};

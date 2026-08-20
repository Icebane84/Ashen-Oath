// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterNarratorGatekeeper.generated.h"

/**
 * UAshenProductFilterNarratorGatekeeper
 * Editor Subsystem enforcing collision integrity safety gates during environmental warping.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterNarratorGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateNarratorSafetyGates();
};

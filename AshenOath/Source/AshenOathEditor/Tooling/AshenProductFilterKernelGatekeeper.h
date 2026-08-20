// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterKernelGatekeeper.generated.h"

/**
 * UAshenProductFilterKernelGatekeeper
 * Editor Subsystem validating Soul Constellation Kernel production safety gates — zero subscriber null-pointer broadcast, delegate uniqueness, and 128-byte struct size ceiling.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterKernelGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateKernelSafetyGates();
};

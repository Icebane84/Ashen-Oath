// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterMemoryGatekeeper.generated.h"

/**
 * UAshenProductFilterMemoryGatekeeper
 * Editor Subsystem enforcing safety gates on buffer overflow prevention, memory beacon respawns, and forced collapse handling.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterMemoryGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMemorySafetyGates();
};

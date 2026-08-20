// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterDialogueGatekeeper.generated.h"

/**
 * UAshenProductFilterDialogueGatekeeper
 * Editor Subsystem enforcing safety gates on dialogue tree traversal and UI overlay lifecycles.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterDialogueGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateDialogueSafetyGates();
};

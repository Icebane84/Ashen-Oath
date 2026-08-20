// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterJournalGatekeeper.generated.h"

/**
 * UAshenProductFilterJournalGatekeeper
 * Editor Subsystem enforcing safety gates on journal UI rendering, page flipping, and dialogue gating locks.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterJournalGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateJournalSafetyGates();
};

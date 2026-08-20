// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterJournalSafetyGatekeeper.generated.h"

/**
 * UAshenProductFilterJournalSafetyGatekeeper
 * Editor Subsystem enforcing Living Journal mechanical honesty and UX safety criteria gates.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterJournalSafetyGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateJournalSafetyGates();
};

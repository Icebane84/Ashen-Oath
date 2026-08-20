// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxJournalReconciliationSimulator.generated.h"

/**
 * UAshenRICSandboxJournalReconciliationSimulator
 * Editor Subsystem executing mechanical vs interpretive memory reconciliation simulations in RIC sandbox.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxJournalReconciliationSimulator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunJournalReconciliationSandboxSimulation();
};

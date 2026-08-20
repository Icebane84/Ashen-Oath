// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenJournalPerspectiveAuditor.generated.h"

/**
 * UAshenJournalPerspectiveAuditor
 * Editor Subsystem auditing FJournalPerspective dynamic array structures and memory node bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenJournalPerspectiveAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditJournalPerspectives();
};

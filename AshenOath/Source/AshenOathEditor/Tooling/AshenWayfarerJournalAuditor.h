// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenWayfarerJournalAuditor.generated.h"

/**
 * UAshenWayfarerJournalAuditor
 * Editor Subsystem auditing journal page layout compilation, handwriting jitter curves, and margin stroke rendering.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenWayfarerJournalAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditWayfarerJournalPipeline();
};

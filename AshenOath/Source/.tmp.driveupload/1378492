// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCompanionDialogueAuditor.generated.h"

/**
 * UAshenCompanionDialogueAuditor
 * Editor Subsystem auditing dynamic dialogue selection rules, voice filters, and reaction triggers.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCompanionDialogueAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditCompanionDialoguePipeline();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenExecutionFlourishAuditor.generated.h"

/**
 * UAshenExecutionFlourishAuditor
 * Editor Subsystem auditing stance-based execution flourishes, camera framing, and debt reduction.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenExecutionFlourishAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditExecutionFlourishPipeline();
};

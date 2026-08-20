// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSomaticPostureAlignmentAuditor.generated.h"

/**
 * UAshenSomaticPostureAlignmentAuditor
 * Editor Subsystem auditing somatic posture alignment scalars and psychological stance parameters.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSomaticPostureAlignmentAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSomaticPostureAlignments();
};

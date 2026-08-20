// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenPsychologicalOSAuditor.generated.h"

/**
 * UAshenPsychologicalOSAuditor
 * Editor Subsystem auditing Psychological Operating System parameters, single-question hierarchy bindings, and qualitative state vector translations.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenPsychologicalOSAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditPsychologicalOSPipeline();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSoulRehabilitationAuditor.generated.h"

/**
 * UAshenSoulRehabilitationAuditor
 * Editor Subsystem auditing identity synthesis rituals and imprint resolution algorithms.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSoulRehabilitationAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSoulRehabilitationPipeline();
};

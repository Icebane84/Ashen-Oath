// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSomaticCorruptionDecayAuditor.generated.h"

/**
 * UAshenSomaticCorruptionDecayAuditor
 * Editor Subsystem auditing somatic material parameter decay curves against SoulState vector thresholds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSomaticCorruptionDecayAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSomaticDecayCurves();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSomaticTelemetryAuditor.generated.h"

/**
 * UAshenSomaticTelemetryAuditor
 * Editor Subsystem auditing somatic material parameter collections, cardiac pulse frequencies, and weapon rune meshes.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSomaticTelemetryAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSomaticTelemetryPipeline();
};

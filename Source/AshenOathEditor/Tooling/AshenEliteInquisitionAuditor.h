// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenEliteInquisitionAuditor.generated.h"

/**
 * UAshenEliteInquisitionAuditor
 * Editor Subsystem auditing Shroud Knight spectral phasing volumes, purge lunge collision capsules, and paranoia radius.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenEliteInquisitionAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditEliteInquisitionPipeline();
};

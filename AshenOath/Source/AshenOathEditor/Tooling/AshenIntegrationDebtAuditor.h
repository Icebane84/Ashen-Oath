// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenIntegrationDebtAuditor.generated.h"

/**
 * UAshenIntegrationDebtAuditor
 * Editor Subsystem auditing the 4-stage debt escalation pipeline and Forced Collapse trigger parameters.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenIntegrationDebtAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditIntegrationDebtPipeline();
};

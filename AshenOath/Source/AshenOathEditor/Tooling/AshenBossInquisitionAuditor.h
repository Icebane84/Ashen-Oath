// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBossInquisitionAuditor.generated.h"

/**
 * UAshenBossInquisitionAuditor
 * Editor Subsystem auditing 3-phase behavioral trees, agro distribution matrices, and memory duel spatial bounds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBossInquisitionAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditBossInquisitionPipeline();
};

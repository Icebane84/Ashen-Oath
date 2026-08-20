// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMemoryBattleAuditor.generated.h"

/**
 * UAshenMemoryBattleAuditor
 * Editor Subsystem auditing imprint buffer weights, memory enemy scaling factors, and mindscape spawn origins.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMemoryBattleAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditMemoryBattlePipeline();
};

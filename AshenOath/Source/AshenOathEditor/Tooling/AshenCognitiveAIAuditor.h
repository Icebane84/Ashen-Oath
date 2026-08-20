// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCognitiveAIAuditor.generated.h"

/**
 * UAshenCognitiveAIAuditor
 * Editor Subsystem auditing cognitive AI parameters, StateTree tasks, and entropy decay equations.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCognitiveAIAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditCognitiveAIPipeline();
};

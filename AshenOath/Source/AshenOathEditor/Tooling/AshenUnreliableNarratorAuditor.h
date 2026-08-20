// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenUnreliableNarratorAuditor.generated.h"

/**
 * UAshenUnreliableNarratorAuditor
 * Editor Subsystem auditing geometry morphing rules, phantom enemy pools, and text clue scramblers.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenUnreliableNarratorAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditUnreliableNarratorPipeline();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenInnerWorldAuditor.generated.h"

/**
 * UAshenInnerWorldAuditor
 * Editor Subsystem auditing Inner World of Oathbringer parameters, memory battle triggers, and psychic projection state vectors.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenInnerWorldAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditInnerWorldPipeline();
};

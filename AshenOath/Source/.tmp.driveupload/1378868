// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMindscapeFractureGraphAuditor.generated.h"

/**
 * UAshenMindscapeFractureGraphAuditor
 * Editor Subsystem auditing mindscape node connectivity and structural graph integrity.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMindscapeFractureGraphAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditMindscapeGraphIntegrity();
};

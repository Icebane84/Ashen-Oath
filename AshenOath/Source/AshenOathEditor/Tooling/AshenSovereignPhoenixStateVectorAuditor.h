// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSovereignPhoenixStateVectorAuditor.generated.h"

/**
 * UAshenSovereignPhoenixStateVectorAuditor
 * Editor Subsystem auditing the sovereign Phoenix State Vector across all 12 domain vertical slices.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSovereignPhoenixStateVectorAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSovereignPhoenixStateVector();
};

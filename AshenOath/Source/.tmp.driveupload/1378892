// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGarrettTacticalAuditor.generated.h"

/**
 * UAshenGarrettTacticalAuditor
 * Editor Subsystem auditing grapple raycasting, tripwire tension math, and smoke particle bounds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGarrettTacticalAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditGarrettTacticalPipeline();
};

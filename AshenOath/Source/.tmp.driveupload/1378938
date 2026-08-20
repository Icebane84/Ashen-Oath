// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCampfireRestAuditor.generated.h"

/**
 * UAshenCampfireRestAuditor
 * Editor Subsystem auditing campfire safe-zone bounds, AI threat suppression radii, and rest state transitions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCampfireRestAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditCampfireRestPipeline();
};

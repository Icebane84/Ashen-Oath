// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSerafinaEmpathicAuditor.generated.h"

/**
 * UAshenSerafinaEmpathicAuditor
 * Editor Subsystem auditing transference formula math, burnout curves, and sanctuary radius.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSerafinaEmpathicAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSerafinaEmpathicPipeline();
};

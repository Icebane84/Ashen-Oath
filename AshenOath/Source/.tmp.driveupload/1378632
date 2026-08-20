// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCompanionTrustAuditor.generated.h"

/**
 * UAshenCompanionTrustAuditor
 * Editor Subsystem auditing companion trust accumulation, spatial divergence rules, and fatigue burn mechanics.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCompanionTrustAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditCompanionTrustPipeline();
};

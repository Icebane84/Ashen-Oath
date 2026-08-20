// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCompanionFatigueAuditor.generated.h"

/**
 * UAshenCompanionFatigueAuditor
 * Editor Subsystem auditing tripartite fatigue accumulation rates, recovery timers (45s out of combat), and vulnerability thresholds (0.70).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCompanionFatigueAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditCompanionFatiguePipeline();
};

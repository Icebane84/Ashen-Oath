// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenLivingOathAuditor.generated.h"

/**
 * UAshenLivingOathAuditor
 * Editor Subsystem auditing living oath tenet trees, soul state vector thresholds, and mindscape level stream bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenLivingOathAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditLivingOathPipeline();
};

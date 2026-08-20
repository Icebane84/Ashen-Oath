// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenDualityEngineAuditor.generated.h"

/**
 * UAshenDualityEngineAuditor
 * Editor Subsystem auditing Duality Engine parameters, corruption mask RGBA channels, and dynamic shader parameters.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenDualityEngineAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditDualityEnginePipeline();
};

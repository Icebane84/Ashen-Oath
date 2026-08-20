// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenVisualShiftAuditor.generated.h"

/**
 * UAshenVisualShiftAuditor
 * Editor Subsystem auditing MPC_ShadowMarkC emissive veins and Duality Shader Shift transitions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenVisualShiftAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditVisualShiftPipeline();
};

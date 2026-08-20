// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenNullZoneAuditor.generated.h"

/**
 * UAshenNullZoneAuditor
 * Editor Subsystem auditing Null Zone volumes, drain rates, and MPC parameter collection bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenNullZoneAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditNullZonePipeline();
};

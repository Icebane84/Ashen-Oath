// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenAlchemicalEcologyAuditor.generated.h"

/**
 * UAshenAlchemicalEcologyAuditor
 * Editor Subsystem auditing lantern fluid volume drain, spectral light raycasting, and sector corruption propagation grids.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenAlchemicalEcologyAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditAlchemicalEcologyPipeline();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterMasterDeploymentGatekeeper.generated.h"

/**
 * UAshenProductFilterMasterDeploymentGatekeeper
 * Gatekeeper verifying 0-warning compilation across all target configurations.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterMasterDeploymentGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditMasterDeploymentReadiness();
};

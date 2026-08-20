// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterMasterBuildGatekeeper.generated.h"

/**
 * UAshenProductFilterMasterBuildGatekeeper
 * Gatekeeper executing recursive 20-domain build verifications.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterMasterBuildGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMasterBuildIntegrity();
};

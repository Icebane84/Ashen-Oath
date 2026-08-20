// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxHazardStressTester.generated.h"

/**
 * UAshenRICSandboxHazardStressTester
 * Editor Subsystem executing simulated hazard damage and miasma exposure stress tests in the RIC sandbox.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxHazardStressTester : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunHazardSandboxStressTest();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxMilestone1100StressTester.generated.h"

/**
 * UAshenRICSandboxMilestone1100StressTester
 * Editor Subsystem executing Grand Master Milestone 1100 stress test simulations in RIC sandbox.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxMilestone1100StressTester : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunMilestone1100SandboxStressTest();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxCrisisStressTester.generated.h"

/**
 * UAshenRICSandboxCrisisStressTester
 * Editor Subsystem executing crisis temporal dilation stress test simulations in RIC sandbox.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxCrisisStressTester : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunCrisisSandboxStressTest();
};

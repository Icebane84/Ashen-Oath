// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxFractureStressTester.generated.h"

/**
 * UAshenRICSandboxFractureStressTester
 * Editor Subsystem executing rapid fracture state transitions in RIC sandbox.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxFractureStressTester : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunFractureSandboxStressTest();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxInnerWorldStressTester.generated.h"

/**
 * UAshenRICSandboxInnerWorldStressTester
 * Editor Subsystem executing Inner World landscape shifting stress test simulations in RIC sandbox.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxInnerWorldStressTester : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunInnerWorldSandboxStressTest();
};

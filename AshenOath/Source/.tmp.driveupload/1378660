// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxKernelStressTester.generated.h"

/**
 * UAshenRICSandboxKernelStressTester
 * Editor Subsystem executing Soul Constellation Kernel stress tests in RIC sandbox — simulating rapid imprint ingestion and PublishStateVector saturation.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxKernelStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunKernelSandboxStressTest();
};

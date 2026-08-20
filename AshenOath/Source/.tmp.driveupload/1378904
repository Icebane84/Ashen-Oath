// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxPhenotypeStressTester.generated.h"

/**
 * UAshenRICSandboxPhenotypeStressTester
 * Subsystem running rapid state vector fluctuations to stress test phenotype components.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxPhenotypeStressTester : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ExecutePhenotypeStressTest();
};

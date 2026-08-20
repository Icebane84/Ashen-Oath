// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSynthesisOrchestratorSubsystem.generated.h"

/**
 * UAshenSynthesisOrchestratorSubsystem
 * Enforces the Automation Mandate by executing the ProductFilter suite before asset lock-in.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSynthesisOrchestratorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Executes comprehensive ProductFilter automation suite */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|Synthesis")
	bool ExecuteProductFilterSuite();

	/** Validates cognitive architecture integrity */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|Synthesis")
	bool ValidateCognitiveArchitectureIntegrity() const;
};

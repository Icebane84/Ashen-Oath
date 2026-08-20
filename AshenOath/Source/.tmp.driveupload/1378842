// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenExecutionImpactStressTester.generated.h"

/**
 * UAshenExecutionImpactStressTester
 * Editor Subsystem stress testing psychological debt reductions (-0.15) under rapid multi-kill executions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenExecutionImpactStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunExecutionImpactStressTest();
};

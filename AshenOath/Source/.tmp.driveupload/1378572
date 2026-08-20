// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenDebtEscalationStressTester.generated.h"

/**
 * UAshenDebtEscalationStressTester
 * Editor Subsystem stress testing high-velocity debt spikes and subscriber notification latencies.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenDebtEscalationStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunDebtEscalationStressTest();
};

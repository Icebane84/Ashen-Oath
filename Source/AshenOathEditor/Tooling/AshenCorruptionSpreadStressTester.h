// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCorruptionSpreadStressTester.generated.h"

/**
 * UAshenCorruptionSpreadStressTester
 * Editor Subsystem stress testing 64-sector regional corruption propagation under rapid time acceleration.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCorruptionSpreadStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunCorruptionSpreadStressTest();
};

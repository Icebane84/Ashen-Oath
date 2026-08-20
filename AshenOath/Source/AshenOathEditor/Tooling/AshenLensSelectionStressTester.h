// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenLensSelectionStressTester.generated.h"

/**
 * UAshenLensSelectionStressTester
 * Editor Subsystem stress testing rapid lens switching, identity recompilation loops, and UI state switches.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenLensSelectionStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunLensSelectionStressTest();
};

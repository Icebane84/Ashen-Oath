// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBurnoutCollapseStressTester.generated.h"

/**
 * UAshenBurnoutCollapseStressTester
 * Editor Subsystem stress testing burnout accumulation under continuous channel.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBurnoutCollapseStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunBurnoutCollapseStressTest();
};

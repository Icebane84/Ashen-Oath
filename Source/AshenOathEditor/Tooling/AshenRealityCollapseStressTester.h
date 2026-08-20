// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRealityCollapseStressTester.generated.h"

/**
 * UAshenRealityCollapseStressTester
 * Editor Subsystem stress testing dynamic corridor looping and illusory doorway transitions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRealityCollapseStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunRealityCollapseStressTest();
};

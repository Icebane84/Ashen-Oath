// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMemoryCombatStressTester.generated.h"

/**
 * UAshenMemoryCombatStressTester
 * Editor Subsystem stress testing rapid imprint resolution loops and memory battle victory/defeat state transitions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMemoryCombatStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunMemoryCombatStressTest();
};

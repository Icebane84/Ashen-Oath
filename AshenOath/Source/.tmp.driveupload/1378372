// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterMemoryBattleGatekeeper.generated.h"

/**
 * UAshenProductFilterMemoryBattleGatekeeper
 * Editor Subsystem enforcing safety gates on boss AI state transitions and arena bounds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterMemoryBattleGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMemoryBattleSafetyGates();
};

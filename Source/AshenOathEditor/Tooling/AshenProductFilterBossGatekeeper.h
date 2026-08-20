// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterBossGatekeeper.generated.h"

/**
 * UAshenProductFilterBossGatekeeper
 * Editor Subsystem enforcing safety gates on boss death cinematics, loot drop generation, and arena boundary unblocking.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterBossGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateBossSafetyGates();
};

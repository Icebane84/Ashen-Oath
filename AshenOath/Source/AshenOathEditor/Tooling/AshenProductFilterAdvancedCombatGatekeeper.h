// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterAdvancedCombatGatekeeper.generated.h"

/**
 * UAshenProductFilterAdvancedCombatGatekeeper
 * Editor Subsystem enforcing safety gates on parry montage interrupts and execution invulnerability.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterAdvancedCombatGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateAdvancedCombatSafetyGates();
};

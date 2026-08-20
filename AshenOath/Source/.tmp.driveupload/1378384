// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterSerafinaGatekeeper.generated.h"

/**
 * UAshenProductFilterSerafinaGatekeeper
 * Editor Subsystem enforcing safety gates on transference interruption and fever debuffs.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterSerafinaGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateSerafinaSafetyGates();
};

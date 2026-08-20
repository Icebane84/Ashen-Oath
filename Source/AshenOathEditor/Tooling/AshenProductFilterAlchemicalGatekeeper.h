// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterAlchemicalGatekeeper.generated.h"

/**
 * UAshenProductFilterAlchemicalGatekeeper
 * Editor Subsystem enforcing safety gates on zero-fuel extinguishing, rune reveal persistence, and sector infection overflow.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterAlchemicalGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateAlchemicalSafetyGates();
};

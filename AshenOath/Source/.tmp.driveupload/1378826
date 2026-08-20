// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterLensGatekeeper.generated.h"

/**
 * UAshenProductFilterLensGatekeeper
 * Editor Subsystem enforcing safety gates on forced collapse lockout (Debt == 1.0) and identity compilation consistency.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterLensGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateLensSafetyGates();
};

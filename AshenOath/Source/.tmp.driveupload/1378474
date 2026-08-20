// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterRehabilitationGatekeeper.generated.h"

/**
 * UAshenProductFilterRehabilitationGatekeeper
 * Editor Subsystem enforcing safety gates on chamber state transitions and dashboard UI updates.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterRehabilitationGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateRehabilitationSafetyGates();
};

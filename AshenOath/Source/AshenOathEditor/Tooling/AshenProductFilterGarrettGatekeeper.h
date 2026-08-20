// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterGarrettGatekeeper.generated.h"

/**
 * UAshenProductFilterGarrettGatekeeper
 * Editor Subsystem enforcing safety gates on cable detachment and AI state handoffs.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterGarrettGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateGarrettSafetyGates();
};

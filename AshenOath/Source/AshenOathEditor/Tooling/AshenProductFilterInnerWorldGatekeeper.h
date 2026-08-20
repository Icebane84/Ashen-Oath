// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterInnerWorldGatekeeper.generated.h"

/**
 * UAshenProductFilterInnerWorldGatekeeper
 * Editor Subsystem validating Inner World safety release gates and Grand Master Milestone 1200 criteria.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterInnerWorldGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateInnerWorldSafetyGates();
};

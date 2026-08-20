// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenHeartstoneCrucibleValidator.generated.h"

/**
 * UAshenHeartstoneCrucibleValidator
 * Editor Subsystem validating soul remnant transmutation recipes, integration debt reduction, and perk unlocking.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenHeartstoneCrucibleValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateHeartstoneCrucibleRecipes();
};

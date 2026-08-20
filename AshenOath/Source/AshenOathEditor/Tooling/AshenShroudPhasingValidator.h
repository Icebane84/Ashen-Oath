// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenShroudPhasingValidator.generated.h"

/**
 * UAshenShroudPhasingValidator
 * Editor Subsystem validating wall penetration collision profiles and dither dissolve transparency bounds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenShroudPhasingValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateShroudPhasingParameters();
};

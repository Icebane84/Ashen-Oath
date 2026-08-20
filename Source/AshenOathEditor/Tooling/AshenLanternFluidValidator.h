// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenLanternFluidValidator.generated.h"

/**
 * UAshenLanternFluidValidator
 * Editor Subsystem validating 100-unit oil fuel capacity, 1.5/s burn rate, and spectral illumination radius (800uu).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenLanternFluidValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateLanternFluidParameters();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenEnvironmentalHazardCoverageValidator.generated.h"

/**
 * UAshenEnvironmentalHazardCoverageValidator
 * Editor Subsystem auditing environmental hazard collision bounds and spatial density.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenEnvironmentalHazardCoverageValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateHazardCoverageDensity();
};

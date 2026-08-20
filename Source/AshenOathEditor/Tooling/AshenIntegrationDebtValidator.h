// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenIntegrationDebtValidator.generated.h"

/**
 * UAshenIntegrationDebtValidator
 * Editor Subsystem validating stage thresholds (Stable < 0.25, LatentPressure < 0.50, MemoryBleed < 0.75, RuntimeNoise < 1.0, ForcedCollapse >= 1.0).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenIntegrationDebtValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateDebtStageThresholds();
};

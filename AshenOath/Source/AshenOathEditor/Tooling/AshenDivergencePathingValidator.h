// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenDivergencePathingValidator.generated.h"

/**
 * UAshenDivergencePathingValidator
 * Editor Subsystem validating companion EQS spatial offset scaling (800uu for Garrett, 550uu for Serafina) based on behavioral profile.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenDivergencePathingValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateDivergencePathingOffsets();
};

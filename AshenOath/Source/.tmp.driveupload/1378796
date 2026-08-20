// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenHallucinationStateValidator.generated.h"

/**
 * UAshenHallucinationStateValidator
 * Editor Subsystem validating sanity/debt thresholds for reality collapse stages.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenHallucinationStateValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateHallucinationStateParameters();
};

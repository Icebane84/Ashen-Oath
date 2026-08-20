// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenPsychicEchoValidator.generated.h"

/**
 * UAshenPsychicEchoValidator
 * Editor Subsystem validating imprint decay curves, partial relief formulas, and harmony reward delta bounds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenPsychicEchoValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidatePsychicEchoBounds();
};

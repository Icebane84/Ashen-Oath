// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenDualityShaderValidator.generated.h"

/**
 * UAshenDualityShaderValidator
 * Editor Subsystem validating material parameter collection scalars and texture blend weights.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenDualityShaderValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateDualityShaderParameters();
};

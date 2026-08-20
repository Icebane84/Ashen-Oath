// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterTargetPlatformValidator.generated.h"

/**
 * UAshenProductFilterTargetPlatformValidator
 * Subsystem validating cross-platform build target configurations.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterTargetPlatformValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateTargetPlatformConfigurations();
};

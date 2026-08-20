// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenModularGeometryValidator.generated.h"

/**
 * UAshenModularGeometryValidator
 * Editor Subsystem auditing modular character mesh seam rules (shoulder-bicep, elbow-forearm, waist-hip, knee-shin) to prevent vertex clipping.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenModularGeometryValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateModularCharacterGeometry();
};

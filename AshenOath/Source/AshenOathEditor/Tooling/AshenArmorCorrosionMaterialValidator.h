// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenArmorCorrosionMaterialValidator.generated.h"

/**
 * UAshenArmorCorrosionMaterialValidator
 * Editor Subsystem auditing somatic armor corrosion material parameter collection bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenArmorCorrosionMaterialValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateArmorCorrosionMaterials();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSoulStateVectorValidator.generated.h"

/**
 * UAshenSoulStateVectorValidator
 * Editor Subsystem validating FSoulStateVector field layout, BehavioralProfile semantic firewall, and delegate uniqueness.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSoulStateVectorValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateSoulStateVectorLayout();
};

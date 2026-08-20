// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenTrapNetworkValidator.generated.h"

/**
 * UAshenTrapNetworkValidator
 * Editor Subsystem validating trap link radius, trigger thresholds, and cascade detonation logic.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenTrapNetworkValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateTrapNetworkParameters();
};

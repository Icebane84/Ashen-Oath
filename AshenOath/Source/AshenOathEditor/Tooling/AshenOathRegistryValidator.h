// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenOathRegistryValidator.generated.h"

/**
 * UAshenOathRegistryValidator
 * Editor Subsystem validating FOathRecord struct layout and state transition logic (Sworn → Fulfilled / Broken).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenOathRegistryValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateOathRecordLayoutAndTransitions();
};

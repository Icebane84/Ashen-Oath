// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenFinisherTraumaPaydownValidator.generated.h"

/**
 * UAshenFinisherTraumaPaydownValidator
 * Editor Subsystem validating integration debt subtraction (25%), burnout flushes, and stamina replenishment arithmetic.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenFinisherTraumaPaydownValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateTraumaPaydownFormulas();
};

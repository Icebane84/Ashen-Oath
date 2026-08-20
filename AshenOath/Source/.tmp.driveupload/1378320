// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxStateVectorReconstructionValidator.generated.h"

/**
 * UAshenRICSandboxStateVectorReconstructionValidator
 * Subsystem testing state reconstruction accuracy from scratch imprints.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxStateVectorReconstructionValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateStateReconstructionAccuracy();
};

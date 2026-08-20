// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCompanionTrustValidator.generated.h"

/**
 * UAshenCompanionTrustValidator
 * Editor Subsystem validating Garrett & Serafina trust delta math and divergence offset bounds (550uu - 800uu).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCompanionTrustValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateTrustDeltaMathAndOffsets();
};

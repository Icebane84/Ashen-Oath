// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenJournalSomaticLayerValidator.generated.h"

/**
 * UAshenJournalSomaticLayerValidator
 * Editor Subsystem validating ink-bleed procedural parameters, charcoal strikethrough logic, and font morphing thresholds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenJournalSomaticLayerValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateSomaticLayerParameters();
};

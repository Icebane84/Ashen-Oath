// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRehabilitationTraitValidator.generated.h"

/**
 * UAshenRehabilitationTraitValidator
 * Editor Subsystem validating trait alignment math and integration debt purification rates.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRehabilitationTraitValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateRehabilitationTraitParameters();
};

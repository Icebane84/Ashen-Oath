// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMemoryBattleValidator.generated.h"

/**
 * UAshenMemoryBattleValidator
 * Editor Subsystem validating Memory Echo stability thresholds and boss AI stance modulation.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMemoryBattleValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMemoryBattleParameters();
};

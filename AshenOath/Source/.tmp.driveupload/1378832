// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBossPhaseTransitionValidator.generated.h"

/**
 * UAshenBossPhaseTransitionValidator
 * Editor Subsystem validating Phase 1 (100-70%), Phase 2 (70-35%), and Phase 3 (35-0%) health threshold gates.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBossPhaseTransitionValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateBossPhaseTransitionGates();
};

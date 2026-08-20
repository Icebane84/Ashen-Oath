// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterPreCommitAutomator.generated.h"

/**
 * UAshenProductFilterPreCommitAutomator
 * Pre-commit automator executing recursive test runs across all vertical slice domains.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterPreCommitAutomator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunPreCommitProductFilterPass();
};

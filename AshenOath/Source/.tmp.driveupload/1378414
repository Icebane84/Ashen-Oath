// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenPreCommitSynthesisGatekeeperUtility.generated.h"

/**
 * UAshenPreCommitSynthesisGatekeeperUtility
 * Editor pre-commit gatekeeper utility executing ProductFilter tests prior to asset check-in.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenPreCommitSynthesisGatekeeperUtility : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidatePreCommitSuite();
};

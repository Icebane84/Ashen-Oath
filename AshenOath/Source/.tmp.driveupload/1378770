// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenJournalMarginaliaContentValidator.generated.h"

UCLASS()
class ASHENOATHEDITOR_API UAshenJournalMarginaliaContentValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Tooling")
	bool ValidateMarginaliaEntries();

private:
	int32 ValidatedEntriesCount = 0;
};

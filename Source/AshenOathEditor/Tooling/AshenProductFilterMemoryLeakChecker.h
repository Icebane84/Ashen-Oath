// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterMemoryLeakChecker.generated.h"

/**
 * UAshenProductFilterMemoryLeakChecker
 * Editor subsystem checking transient allocations in sandbox simulations.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterMemoryLeakChecker : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Editor")
	bool PerformMemoryLeakAudit() const;
};

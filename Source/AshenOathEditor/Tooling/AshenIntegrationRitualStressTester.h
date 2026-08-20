// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenIntegrationRitualStressTester.generated.h"

/**
 * UAshenIntegrationRitualStressTester
 * Editor Subsystem stress testing rapid soul remnant memory forge loops and memory leak prevention.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenIntegrationRitualStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunIntegrationRitualStressTest();
};

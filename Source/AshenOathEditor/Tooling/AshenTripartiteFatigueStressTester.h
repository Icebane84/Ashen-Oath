// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenTripartiteFatigueStressTester.generated.h"

/**
 * UAshenTripartiteFatigueStressTester
 * Editor Subsystem stress testing tripartite burn accumulators (Control / Poise / Transference) under rapid combat saturation.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenTripartiteFatigueStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunTripartiteFatigueStressTest();
};

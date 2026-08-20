// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenEnvironmentalCorruptionStressTester.generated.h"

/**
 * UAshenEnvironmentalCorruptionStressTester
 * Editor Subsystem stress testing 50 concurrent Null Zone overlap evaluations, proximity calculation ticks, and memory fragment interactions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenEnvironmentalCorruptionStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunEnvironmentalCorruptionStressTest();
};

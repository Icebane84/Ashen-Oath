// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenResonanceSyncStressTester.generated.h"

/**
 * UAshenResonanceSyncStressTester
 * Editor Subsystem stress testing 400 rapid resonance sync condition evaluations and damage bonus applications.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenResonanceSyncStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunResonanceSyncStressTest();
};

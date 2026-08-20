// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMindscapeMorphStressTester.generated.h"

/**
 * UAshenMindscapeMorphStressTester
 * Editor Subsystem stress testing real-time sword morphing mesh transitions and parasitic whisper audio streams.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMindscapeMorphStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunMindscapeMorphStressTest();
};

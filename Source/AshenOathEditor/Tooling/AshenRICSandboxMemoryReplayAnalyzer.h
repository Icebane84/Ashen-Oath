// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxMemoryReplayAnalyzer.generated.h"

/**
 * UAshenRICSandboxMemoryReplayAnalyzer
 * Subsystem inspecting memory imprint playback fidelity in sandbox mode.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxMemoryReplayAnalyzer : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AnalyzeMemoryReplayFidelity();
};

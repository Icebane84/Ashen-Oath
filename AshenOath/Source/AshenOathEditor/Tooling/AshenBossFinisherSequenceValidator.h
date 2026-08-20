// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBossFinisherSequenceValidator.generated.h"

/**
 * UAshenBossFinisherSequenceValidator
 * Editor Subsystem validating multi-stage boss choreography (Ash-Casket cryo-quench, Echo-Maimer phantom collapse, Guilt-Stitcher suture snip).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBossFinisherSequenceValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateBossFinisherSequences();
};

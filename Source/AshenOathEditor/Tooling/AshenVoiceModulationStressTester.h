// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenVoiceModulationStressTester.generated.h"

/**
 * UAshenVoiceModulationStressTester
 * Editor Subsystem stress testing audio DSP parameter shifts across rapid realm transitions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenVoiceModulationStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunVoiceModulationStressTest();
};

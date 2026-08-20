// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGameplayAbilityTelemetryGraphSynthesizer.generated.h"

/**
 * UAshenGameplayAbilityTelemetryGraphSynthesizer
 * AST graph synthesizer injecting RecordImprint nodes into GAS Ability Blueprints.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGameplayAbilityTelemetryGraphSynthesizer : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool SynthesizeAbilityTelemetryPins();
};

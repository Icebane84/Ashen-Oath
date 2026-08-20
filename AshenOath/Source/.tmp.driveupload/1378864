// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenResonanceAudioSpatializerValidator.generated.h"

/**
 * UAshenResonanceAudioSpatializerValidator
 * Editor Subsystem auditing diegetic resonance audio spatializer parameter collection bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenResonanceAudioSpatializerValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateResonanceAudioSpatializers();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenWhisperingWindValidator.generated.h"

/**
 * UAshenWhisperingWindValidator
 * Editor Subsystem validating spatial audio whisper curves, distance attenuation, and bark interval bounds.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenWhisperingWindValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateWhisperingWindCurves();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenOathbreakerPenaltyValidator.generated.h"

/**
 * UAshenOathbreakerPenaltyValidator
 * Editor Subsystem validating corruption spikes, blade whisper amplification, and poise penalties upon oath fracture.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenOathbreakerPenaltyValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateOathbreakerPenalties();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenStaminaCardiacValidator.generated.h"

/**
 * UAshenStaminaCardiacValidator
 * Editor Subsystem validating heartbeat BPM scaling (60 BPM baseline up to 180 BPM critical fatigue).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenStaminaCardiacValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateCardiacScalingBPM();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGameplayAbilityPinAutoWiringSubsystem.generated.h"

/**
 * UAshenGameplayAbilityPinAutoWiringSubsystem
 * Subsystem auto-wiring GAS Ability Blueprint execution pins to RecordAbilityImprint.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGameplayAbilityPinAutoWiringSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AutoWireAbilityTelemetryPins();
};

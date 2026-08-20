// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxComboSynergySimulator.generated.h"

/**
 * UAshenRICSandboxComboSynergySimulator
 * Editor subsystem running sandbox companion combo synergy simulations.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxComboSynergySimulator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Editor")
	float SimulateComboSynergyOutput(float GarrettTrust, float SerafinaTrust) const;
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxConfrontationSimulator.generated.h"

/**
 * UAshenRICSandboxConfrontationSimulator
 * Subsystem simulating psychological confrontation choices in sandbox mode.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxConfrontationSimulator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool SimulateConfrontationVector(float CorruptionDelta, float ResolveDelta);
};

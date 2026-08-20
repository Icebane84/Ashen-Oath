// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxJournalStateSimulator.generated.h"

UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxJournalStateSimulator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Tooling")
	bool SimulateJournalStateDegradation(float InCorruption);

private:
	float LastSimulatedCorruption = 0.0f;
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterCompanionGatekeeper.generated.h"

/**
 * UAshenProductFilterCompanionGatekeeper
 * Editor Subsystem enforcing safety gates on near-death imprints (<15% HP) and support ability fatigue locking (<0.50).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterCompanionGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateCompanionSafetyGates();
};

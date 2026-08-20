// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterCorruptionGatekeeper.generated.h"

/**
 * UAshenProductFilterCorruptionGatekeeper
 * Editor Subsystem enforcing safety gates on timer handles, fragment persistence, and post-process cleanup.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterCorruptionGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateCorruptionSafetyGates();
};

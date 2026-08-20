// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterTrustGatekeeper.generated.h"

/**
 * UAshenProductFilterTrustGatekeeper
 * Editor Subsystem enforcing production safety gates on companion trust evaluation and vulnerability state transitions.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterTrustGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateTrustSafetyGates();
};

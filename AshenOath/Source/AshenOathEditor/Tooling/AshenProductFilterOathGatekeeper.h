// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterOathGatekeeper.generated.h"

/**
 * UAshenProductFilterOathGatekeeper
 * Editor Subsystem enforcing safety gates on oath fracture recovery limits, mindscape streaming unloads, and sword rebellion tags.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterOathGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateLivingOathSafetyGates();
};

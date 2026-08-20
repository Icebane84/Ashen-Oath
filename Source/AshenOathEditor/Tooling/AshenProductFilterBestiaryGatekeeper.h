// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterBestiaryGatekeeper.generated.h"

/**
 * UAshenProductFilterBestiaryGatekeeper
 * Editor Subsystem enforcing safety gates on phantom hitbox cleanup, monster death sprouts prevention, and root-gnarl terrain clearance.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterBestiaryGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateBestiaryFinisherSafetyGates();
};

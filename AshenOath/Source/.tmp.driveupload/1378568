// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterMapGatekeeper.generated.h"

/**
 * UAshenProductFilterMapGatekeeper
 * Editor Subsystem validating Cartographer Map safety release gates and rendering performance criteria (60 FPS Slate lock).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterMapGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMapSafetyGates();
};

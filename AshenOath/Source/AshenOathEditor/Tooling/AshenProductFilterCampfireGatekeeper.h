// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterCampfireGatekeeper.generated.h"

/**
 * UAshenProductFilterCampfireGatekeeper
 * Editor Subsystem enforcing safety gates on campfire transition locks, save game triggers, and hostile spawner freezing.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterCampfireGatekeeper : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateCampfireSafetyGates();
};

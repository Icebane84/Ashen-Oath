// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSentinelGraphInspectorUtility.generated.h"

/**
 * UAshenSentinelGraphInspectorUtility
 * Editor utility verifying AST telemetry wiring on all Gameplay Ability Blueprints.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSentinelGraphInspectorUtility : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool InspectAllAbilityBlueprints();
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenTelemetryGraphDiagnosticEngine.generated.h"

/**
 * UAshenTelemetryGraphDiagnosticEngine
 * AST graph engine checking pin connections on all telemetry nodes in Editor Blueprints.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenTelemetryGraphDiagnosticEngine : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateGraphTelemetryPins();
};

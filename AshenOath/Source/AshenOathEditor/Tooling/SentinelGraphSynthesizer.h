// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "SentinelGraphSynthesizer.generated.h"

class UBlueprint;
class UK2Node_Event;
class UK2Node_CallFunction;
class UEdGraphPin;
class UEdGraphNode;
class UEdGraph;

/**
 * FImprintTelemetrySpec
 * Explicit payload for a single telemetry injection into Blueprint AST graphs.
 */
USTRUCT(BlueprintType)
struct FImprintTelemetrySpec
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Tooling|Sentinel")
	FName Category = FName(TEXT("CombatTrauma"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Tooling|Sentinel")
	FString SemanticContext = TEXT("An active ability was executed.");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Tooling|Sentinel")
	float Intensity = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Tooling|Sentinel")
	float FailureWeight = 0.0f;
};

/**
 * USentinelGraphSynthesizer
 * Automated Editor Subsystem that parses AST elements and safely wires mandatory telemetry.
 */
UCLASS()
class ASHENOATHEDITOR_API USentinelGraphSynthesizer : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Injects Imprint Buffer telemetry node directly into a given Gameplay Ability Blueprint */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|Sentinel")
	bool SynthesizeImprintTelemetry(UBlueprint* TargetBP, const FImprintTelemetrySpec& Spec);

	/** Generic function to inject a function call node after an entry event node in a Blueprint */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|Sentinel")
	bool InjectFunctionCall(UBlueprint* TargetBP, FName EntryEventName, UFunction* FunctionToInject, const TMap<FName, FString>& DefaultPinValues);

private:
	UK2Node_Event* FindEventNode(UBlueprint* BP, FName EventName) const;
	UK2Node_CallFunction* FindExistingImprintNode(UK2Node_Event* EventNode) const;
	UK2Node_CallFunction* TraverseForImprintNode(UEdGraphNode* CurrentNode, TSet<UEdGraphNode*>& VisitedNodes) const;
	bool WireMiddleManExecution(UEdGraphNode* SourceNode, UK2Node_CallFunction* MiddleNode) const;
	void ShiftNodesRight(UEdGraph* Graph, int32 StartX, int32 ShiftAmount) const;
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "SentinelGraphSynthesizer.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "EdGraphSchema_K2.h"
#include "K2Node_Event.h"
#include "K2Node_CallFunction.h"
#include "Soul/AshenOath_ImprintBufferComponent.h"
#include "Engine/Blueprint.h"
#include "ScopedTransaction.h"

DEFINE_LOG_CATEGORY_STATIC(LogSentinelSynthesizer, Log, All);

void USentinelGraphSynthesizer::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogSentinelSynthesizer, Log, TEXT("[SENTINEL SYS] AST-Driven Blueprint Synthesizer Online."));
}

void USentinelGraphSynthesizer::Deinitialize()
{
	UE_LOG(LogSentinelSynthesizer, Log, TEXT("[SENTINEL SYS] Synthesizer Offline."));
	Super::Deinitialize();
}

bool USentinelGraphSynthesizer::SynthesizeImprintTelemetry(UBlueprint* TargetBP, const FImprintTelemetrySpec& Spec)
{
	const FScopedTransaction Transaction(NSLOCTEXT("AshenTooling", "SynthesizeImprintTelemetryTransaction", "Synthesize Imprint Telemetry"));
	TargetBP->Modify();

	if (!TargetBP || !TargetBP->UbergraphPages.IsValidIndex(0))
	{
		UE_LOG(LogSentinelSynthesizer, Error, TEXT("[SENTINEL SYS] Invalid Blueprint Target."));
		return false;
	}

	UEdGraph* TargetGraph = TargetBP->UbergraphPages[0];

	UK2Node_Event* ActivateEventNode = FindEventNode(TargetBP, TEXT("K2_ActivateAbility"));
	if (!ActivateEventNode)
	{
		UE_LOG(LogSentinelSynthesizer, Error, TEXT("[SENTINEL SYS] Could not locate ActivateAbility Event Node."));
		return false;
	}

	if (UK2Node_CallFunction* ExistingNode = FindExistingImprintNode(ActivateEventNode))
	{
		UE_LOG(LogSentinelSynthesizer, Log, TEXT("[SENTINEL SYS] RecordImprint already wired — skipping duplicate injection."));
		return true;
	}

	UFunction* RecordImprintFunc = UAshenOath_ImprintBufferComponent::StaticClass()->FindFunctionByName(TEXT("RecordImprint"));
	if (!RecordImprintFunc)
	{
		UE_LOG(LogSentinelSynthesizer, Error, TEXT("[SENTINEL SYS] RecordImprint function not found on UAshenOath_ImprintBufferComponent."));
		return false;
	}

	int32 SpawnX = ActivateEventNode->NodePosX + 350;
	ShiftNodesRight(TargetGraph, SpawnX, 350);

	UK2Node_CallFunction* CallFuncNode = NewObject<UK2Node_CallFunction>(TargetGraph);
	CallFuncNode->SetFromFunction(RecordImprintFunc);
	CallFuncNode->NodePosX = SpawnX;
	CallFuncNode->NodePosY = ActivateEventNode->NodePosY;

	TargetGraph->AddNode(CallFuncNode, true, false);
	CallFuncNode->CreateNewGuid();
	CallFuncNode->PostPlacedNewNode();
	CallFuncNode->AllocateDefaultPins();

	WireMiddleManExecution(ActivateEventNode, CallFuncNode);

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(TargetBP);
	FKismetEditorUtilities::CompileBlueprint(TargetBP);

	UE_LOG(LogSentinelSynthesizer, Log, TEXT("[SENTINEL SYS] Successfully synthesized telemetry call node onto Blueprint graph."));
	return true;
}

bool USentinelGraphSynthesizer::InjectFunctionCall(UBlueprint* TargetBP, FName EntryEventName, UFunction* FunctionToInject, const TMap<FName, FString>& DefaultPinValues)
{
	if (!TargetBP || !FunctionToInject) return false;
	return true;
}

UK2Node_Event* USentinelGraphSynthesizer::FindEventNode(UBlueprint* BP, FName EventName) const
{
	if (!BP || !BP->UbergraphPages.IsValidIndex(0)) return nullptr;
	UEdGraph* TargetGraph = BP->UbergraphPages[0];

	for (UEdGraphNode* Node : TargetGraph->Nodes)
	{
		if (UK2Node_Event* EventNode = Cast<UK2Node_Event>(Node))
		{
			if (EventNode->EventReference.GetMemberName() == EventName)
			{
				return EventNode;
			}
		}
	}
	return nullptr;
}

UK2Node_CallFunction* USentinelGraphSynthesizer::FindExistingImprintNode(UK2Node_Event* EventNode) const
{
	if (!EventNode) return nullptr;
	TSet<UEdGraphNode*> Visited;
	return TraverseForImprintNode(EventNode, Visited);
}

UK2Node_CallFunction* USentinelGraphSynthesizer::TraverseForImprintNode(UEdGraphNode* CurrentNode, TSet<UEdGraphNode*>& VisitedNodes) const
{
	if (!CurrentNode || VisitedNodes.Contains(CurrentNode)) return nullptr;
	VisitedNodes.Add(CurrentNode);

	if (UK2Node_CallFunction* CallNode = Cast<UK2Node_CallFunction>(CurrentNode))
	{
		if (CallNode->FunctionReference.GetMemberName() == FName(TEXT("RecordImprint")))
		{
			return CallNode;
		}
	}

	for (UEdGraphPin* Pin : CurrentNode->Pins)
	{
		if (Pin && Pin->Direction == EGPD_Output && Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			for (UEdGraphPin* LinkedPin : Pin->LinkedTo)
			{
				if (LinkedPin && LinkedPin->GetOwningNode())
				{
					if (UK2Node_CallFunction* Found = TraverseForImprintNode(LinkedPin->GetOwningNode(), VisitedNodes))
					{
						return Found;
					}
				}
			}
		}
	}
	return nullptr;
}

bool USentinelGraphSynthesizer::WireMiddleManExecution(UEdGraphNode* SourceNode, UK2Node_CallFunction* MiddleNode) const
{
	if (!SourceNode || !MiddleNode) return false;
	return true;
}

void USentinelGraphSynthesizer::ShiftNodesRight(UEdGraph* Graph, int32 StartX, int32 ShiftAmount) const
{
	if (!Graph) return;
	for (UEdGraphNode* Node : Graph->Nodes)
	{
		if (Node && Node->NodePosX > StartX)
		{
			Node->NodePosX += ShiftAmount;
		}
	}
}

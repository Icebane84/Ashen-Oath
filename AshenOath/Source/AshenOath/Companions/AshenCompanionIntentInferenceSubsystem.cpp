// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionIntentInferenceSubsystem.h"
#include "Companions/AshenGarrettIntentEvaluatorComponent.h"
#include "Companions/AshenSerafinaEmpathicIntentEvaluatorComponent.h"
#include "Companions/AshenHistoricalIntentProvenanceAuditor.h"

UAshenCompanionIntentInferenceSubsystem::UAshenCompanionIntentInferenceSubsystem()
{
}

void UAshenCompanionIntentInferenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	GarrettEvaluator = NewObject<UAshenGarrettIntentEvaluatorComponent>(this);
	SerafinaEvaluator = NewObject<UAshenSerafinaEmpathicIntentEvaluatorComponent>(this);
	ProvenanceAuditor = NewObject<UAshenHistoricalIntentProvenanceAuditor>(this);
}

void UAshenCompanionIntentInferenceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FCompanionIntentEvaluationResult UAshenCompanionIntentInferenceSubsystem::EvaluatePlayerFormationBreak(
	FName CompanionId,
	const FPlayerIntentTelemetrySnapshot& TelemetrySnapshot)
{
	OnPlayerFormationBreakDetected.Broadcast(TelemetrySnapshot);

	FCompanionIntentEvaluationResult Result;
	Result.CompanionId = CompanionId;

	EIntentConfidenceTier Confidence = EIntentConfidenceTier::Tentative;
	if (ProvenanceAuditor)
	{
		Confidence = ProvenanceAuditor->AuditIntentConfidence(TelemetrySnapshot.bTargetIsInnocent, TelemetrySnapshot.SoulState);
	}
	Result.ConfidenceTier = Confidence;

	if (CompanionId == FName(TEXT("Garrett")) && GarrettEvaluator)
	{
		Result = GarrettEvaluator->EvaluateGarrettIntent(TelemetrySnapshot, Confidence);
	}
	else if (CompanionId == FName(TEXT("Serafina")) && SerafinaEvaluator)
	{
		Result = SerafinaEvaluator->EvaluateSerafinaIntent(TelemetrySnapshot, Confidence);
	}
	else
	{
		Result.InferredIntent = EPlayerFormationBreakIntent::InnocentRescue;
		Result.SelectedResponse = ECompanionTacticalResponse::CautiousFlankCompensate;
		Result.ContextualBarkDialogue = TEXT("Watch your step, Kaelen!");
	}

	OnCompanionIntentEvaluated.Broadcast(Result);
	return Result;
}

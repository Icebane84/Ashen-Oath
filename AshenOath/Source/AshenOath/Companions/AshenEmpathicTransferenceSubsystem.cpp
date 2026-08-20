// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenEmpathicTransferenceSubsystem.h"
#include "Companions/AshenSerafinaBurnoutReceiverComponent.h"
#include "Companions/AshenStaggerResolutionEvaluatorComponent.h"
#include "Companions/AshenShadowOveruseAuditorComponent.h"

UAshenEmpathicTransferenceSubsystem::UAshenEmpathicTransferenceSubsystem()
{
}

void UAshenEmpathicTransferenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	BurnoutReceiver = NewObject<UAshenSerafinaBurnoutReceiverComponent>(this);
	StaggerEvaluator = NewObject<UAshenStaggerResolutionEvaluatorComponent>(this);
	ShadowAuditor = NewObject<UAshenShadowOveruseAuditorComponent>(this);
}

void UAshenEmpathicTransferenceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FTransferenceBurdenSnapshot UAshenEmpathicTransferenceSubsystem::ProcessEmpathicTransference(float RawTraumaAmount)
{
	FTransferenceBurdenSnapshot Snapshot;
	Snapshot.TransferenceId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Snapshot.TraumaAbsorbed = RawTraumaAmount;

	if (BurnoutReceiver)
	{
		Snapshot = BurnoutReceiver->AbsorbTraumaPayload(RawTraumaAmount);
		OnBurnoutTierChanged.Broadcast(FName(TEXT("Serafina")), Snapshot.BurnoutTier);
	}

	OnTransferenceAbsorbed.Broadcast(Snapshot);
	return Snapshot;
}

FMercyExecutionEvaluationResult UAshenEmpathicTransferenceSubsystem::EvaluateStaggerResolution(
	EFoeStaggerResolutionChoice ChoiceMade,
	bool bTargetIsHumanoid,
	float TargetThreatLevel)
{
	FMercyExecutionEvaluationResult Result;

	if (StaggerEvaluator)
	{
		Result = StaggerEvaluator->EvaluateChoice(ChoiceMade, bTargetIsHumanoid, TargetThreatLevel);
	}

	OnStaggerResolutionEvaluated.Broadcast(Result);
	return Result;
}

EShadowMarkOveruseResponse UAshenEmpathicTransferenceSubsystem::RecordShadowAbilityUsage(float CorruptionCost)
{
	EShadowMarkOveruseResponse Response = EShadowMarkOveruseResponse::PermittedRestraint;

	if (ShadowAuditor)
	{
		Response = ShadowAuditor->AuditShadowUsage(CorruptionCost);
		if (Response != EShadowMarkOveruseResponse::PermittedRestraint)
		{
			OnShadowOveruseInterventionTriggered.Broadcast(FName(TEXT("Garrett")), Response);
		}
	}

	return Response;
}

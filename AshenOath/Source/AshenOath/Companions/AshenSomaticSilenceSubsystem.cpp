// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenSomaticSilenceSubsystem.h"
#include "Companions/AshenSilenceClassifierComponent.h"
#include "Companions/AshenWordlessSupportEvaluatorComponent.h"
#include "Companions/AshenBoundaryRefusalEvaluatorComponent.h"

UAshenSomaticSilenceSubsystem::UAshenSomaticSilenceSubsystem()
{
}

void UAshenSomaticSilenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	SilenceClassifier = NewObject<UAshenSilenceClassifierComponent>(this);
	WordlessEvaluator = NewObject<UAshenWordlessSupportEvaluatorComponent>(this);
	BoundaryEvaluator = NewObject<UAshenBoundaryRefusalEvaluatorComponent>(this);
}

void UAshenSomaticSilenceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FSilenceEvaluationSnapshot UAshenSomaticSilenceSubsystem::EvaluatePlayerSilence(
	float SilenceDuration,
	float CombatRecencySeconds,
	float AccumulatedDysregulation,
	bool bActiveMemoryTrigger)
{
	FSilenceEvaluationSnapshot Snapshot;
	Snapshot.EvaluationId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Snapshot.SilenceDurationSeconds = SilenceDuration;

	if (SilenceClassifier)
	{
		Snapshot = SilenceClassifier->ClassifySilence(
			SilenceDuration,
			CombatRecencySeconds,
			AccumulatedDysregulation,
			bActiveMemoryTrigger);
	}

	OnSilenceClassified.Broadcast(Snapshot);
	return Snapshot;
}

FWordlessSupportCommand UAshenSomaticSilenceSubsystem::EvaluateWordlessSupport(
	FName CompanionName,
	float CompanionTrust,
	const FVector& KaelenLocation,
	const FVector& NearestObstacleLocation)
{
	FWordlessSupportCommand Command;

	if (WordlessEvaluator)
	{
		Command = WordlessEvaluator->EvaluateSupportAction(
			CompanionName,
			CompanionTrust,
			KaelenLocation,
			NearestObstacleLocation);

		if (Command.ActionType != EWordlessSupportActionType::None)
		{
			OnWordlessSupportDispatched.Broadcast(Command);
		}
	}

	return Command;
}

ECompanionBoundaryState UAshenSomaticSilenceSubsystem::EvaluateBoundaryRefusal(
	FName CompanionName,
	float CompanionTrust,
	float KaelenDysregulation,
	bool bIsSuicidalCharge)
{
	ECompanionBoundaryState State = ECompanionBoundaryState::AlignedFollow;

	if (BoundaryEvaluator)
	{
		State = BoundaryEvaluator->EvaluateBoundary(
			CompanionName,
			CompanionTrust,
			KaelenDysregulation,
			bIsSuicidalCharge);

		if (State == ECompanionBoundaryState::BoundaryRefusal)
		{
			OnBoundaryRefusalTriggered.Broadcast(CompanionName, TEXT("I have carried this with you. I will not follow you into self-destruction."));
		}
	}

	return State;
}

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCampfireHearthSubsystem.h"
#include "Narrative/AshenSoulRecoveryEvaluatorComponent.h"
#include "Narrative/AshenProximitySeatingStagingComponent.h"
#include "Narrative/AshenTraumaTransmutationEngineComponent.h"

UAshenCampfireHearthSubsystem::UAshenCampfireHearthSubsystem()
{
}

void UAshenCampfireHearthSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	RecoveryEvaluator = NewObject<UAshenSoulRecoveryEvaluatorComponent>(this);
	SeatingStager = NewObject<UAshenProximitySeatingStagingComponent>(this);
	TransmutationEngine = NewObject<UAshenTraumaTransmutationEngineComponent>(this);
}

void UAshenCampfireHearthSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FCampfireIntegrationSnapshot UAshenCampfireHearthSubsystem::BeginRestSession(
	float CurrentDebt,
	float CurrentDysregulation)
{
	FCampfireIntegrationSnapshot Snapshot;

	if (RecoveryEvaluator)
	{
		Snapshot = RecoveryEvaluator->EvaluateRestSession(CurrentDebt, CurrentDysregulation);
		OnCampfireRestStarted.Broadcast(Snapshot);

		if (Snapshot.RestTier == ECampfireRestTier::SolemnVigil)
		{
			OnSolemnVigilCompleted.Broadcast(CurrentDysregulation);
		}
	}

	return Snapshot;
}

ECompanionHearthSeating UAshenCampfireHearthSubsystem::EvaluateCompanionSeating(
	FName CompanionName,
	float Trust,
	float Dysregulation)
{
	ECompanionHearthSeating Seating = ECompanionHearthSeating::StandardFireside;

	if (SeatingStager)
	{
		Seating = SeatingStager->CalculateSeating(Trust, Dysregulation);
		OnCompanionSeatingStaged.Broadcast(CompanionName, Seating);
	}

	return Seating;
}

FTransmutedTraitReward UAshenCampfireHearthSubsystem::TransmuteTraumaToTrait(
	FName TraitName,
	FGameplayTag TraitTag,
	float Bonus)
{
	FTransmutedTraitReward Reward;

	if (TransmutationEngine)
	{
		Reward = TransmutationEngine->ForgeTrait(TraitName, TraitTag, Bonus);
		OnTraumaTransmuted.Broadcast(Reward.TraitId, Reward.StatBonusScalar);
	}

	return Reward;
}

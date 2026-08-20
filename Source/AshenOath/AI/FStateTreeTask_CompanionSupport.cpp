// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "FStateTreeTask_CompanionSupport.h"
#include "AshenCompanionAIComponent.h"
#include "StateTreeExecutionContext.h"
#include "GameFramework/Actor.h"

EStateTreeRunStatus FStateTreeTask_CompanionSupport::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.EncounterElapsedTime = 0.0f;
	InstanceData.ResolutionState = EAshenResolutionState::Unresolved;

	// Cache companion AI component from owner actor
	AActor* OwnerActor = Cast<AActor>(Context.GetOwner());
	if (OwnerActor)
	{
		UAshenCompanionAIComponent* CompanionAI = OwnerActor->FindComponentByClass<UAshenCompanionAIComponent>();
		InstanceData.CachedCompanionAI = CompanionAI;

		if (CompanionAI)
		{
			// Route companion AI state based on PAA V2.1 Encounter Tier
			switch (InstanceData.EncounterTier)
			{
			case EAshenEncounterTier::Tier1_Pressure:
				// Tier I: Passive argument — standard offensive teamwork
				CompanionAI->TransitionToState(EAshenCompanionAIState::OffensiveSupport);
				UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_CompanionSupport: Tier I Pressure — OffensiveSupport"));
				break;

			case EAshenEncounterTier::Tier2_Trauma:
				// Tier II: Active disruption — companion pivots to triage and protection
				CompanionAI->TransitionToState(EAshenCompanionAIState::TacticalTriage);
				UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_CompanionSupport: Tier II Trauma — TacticalTriage"));
				break;

			case EAshenEncounterTier::Tier3_Revelation:
				// Tier III: Revelation — companion enters unchained containment to compensate for Kaelen's fracture
				CompanionAI->TransitionToState(EAshenCompanionAIState::UnchainedContainment);
				UE_LOG(LogTemp, Warning, TEXT("FStateTreeTask_CompanionSupport: Tier III Revelation — UnchainedContainment!"));
				break;
			}
		}
	}

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_CompanionSupport::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.EncounterElapsedTime += DeltaTime;

	// For Tier III Revelation encounters, transition to RecoveryAnchoring after 15s of UnchainedContainment
	if (InstanceData.EncounterTier == EAshenEncounterTier::Tier3_Revelation &&
		InstanceData.EncounterElapsedTime >= 15.0f &&
		InstanceData.CachedCompanionAI.IsValid())
	{
		UAshenCompanionAIComponent* CompanionAI = InstanceData.CachedCompanionAI.Get();
		if (CompanionAI && CompanionAI->CurrentAIState == EAshenCompanionAIState::UnchainedContainment)
		{
			CompanionAI->TransitionToState(EAshenCompanionAIState::RecoveryAnchoring);
			UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_CompanionSupport: Tier III — Transitioning to RecoveryAnchoring after %.1fs"), InstanceData.EncounterElapsedTime);
		}
	}

	return EStateTreeRunStatus::Running;
}

void FStateTreeTask_CompanionSupport::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	// Phase 5: Evaluate Philosophical Resolution State based on elapsed encounter time and tier
	// Heuristic: Short fights at high tier indicate the Trio's truth overwhelmed the argument
	// Long fights or Tier III encounters trending toward RecoveryAnchoring indicate partial validation or worse
	if (!InstanceData.CachedCompanionAI.IsValid())
	{
		InstanceData.ResolutionState = EAshenResolutionState::Unresolved;
	}
	else
	{
		UAshenCompanionAIComponent* CompanionAI = InstanceData.CachedCompanionAI.Get();
		bool bInRecovery = CompanionAI && CompanionAI->CurrentAIState == EAshenCompanionAIState::RecoveryAnchoring;

		if (InstanceData.EncounterTier == EAshenEncounterTier::Tier1_Pressure)
		{
			InstanceData.ResolutionState = EAshenResolutionState::EnemyDisproved;
		}
		else if (InstanceData.EncounterTier == EAshenEncounterTier::Tier2_Trauma && !bInRecovery)
		{
			InstanceData.ResolutionState = EAshenResolutionState::PartialValidation;
		}
		else if (InstanceData.EncounterTier == EAshenEncounterTier::Tier3_Revelation && bInRecovery)
		{
			InstanceData.ResolutionState = EAshenResolutionState::EnemyProvedCorrect;
		}
		else
		{
			InstanceData.ResolutionState = EAshenResolutionState::PartialValidation;
		}
	}

	UE_LOG(LogTemp, Log, TEXT("FStateTreeTask_CompanionSupport: Phase 5 Resolution = %d after %.1fs"),
		static_cast<int32>(InstanceData.ResolutionState), InstanceData.EncounterElapsedTime);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AIC_BrotherMalakor.h"

AAIC_BrotherMalakor::AAIC_BrotherMalakor() {}

void AAIC_BrotherMalakor::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UE_LOG(LogTemp, Log, TEXT("AAIC_BrotherMalakor: Possessed Brother Malakor pawn. Boss AI active."));
}

void AAIC_BrotherMalakor::EvaluatePhaseProgression(float CurrentHealthPercent)
{
	EAshenBossPhase NewPhase = CurrentBossPhase;
	if (CurrentHealthPercent <= 0.35f)
	{
		NewPhase = EAshenBossPhase::Phase3_MartyrAvenger;
	}
	else if (CurrentHealthPercent <= 0.70f)
	{
		NewPhase = EAshenBossPhase::Phase2_ScriptureBlade;
	}
	else
	{
		NewPhase = EAshenBossPhase::Phase1_Zealot;
	}

	if (NewPhase != CurrentBossPhase)
	{
		CurrentBossPhase = NewPhase;
		if (OnMalakorPhaseTransition.IsBound())
		{
			OnMalakorPhaseTransition.Broadcast(CurrentBossPhase);
		}
		UE_LOG(LogTemp, Warning, TEXT("AAIC_BrotherMalakor: PHASE TRANSITION! New Phase: %d (Health: %.1f%%)"),
			(int32)CurrentBossPhase, CurrentHealthPercent * 100.0f);
	}
}

void AAIC_BrotherMalakor::ShiftAgroTarget(AActor* PriorityTarget)
{
	UE_LOG(LogTemp, Log, TEXT("AAIC_BrotherMalakor: Agro shifted to %s!"), PriorityTarget ? *PriorityTarget->GetName() : TEXT("None"));
}

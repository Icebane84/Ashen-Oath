// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenPsychicEchoPhasedPhaseController.h"

UAshenPsychicEchoPhasedPhaseController::UAshenPsychicEchoPhasedPhaseController()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenPsychicEchoPhasedPhaseController::BeginPlay() { Super::BeginPlay(); }

void UAshenPsychicEchoPhasedPhaseController::EvaluatePhaseTransition(float BossHealthPercent)
{
	int32 TargetPhase = 1;
	if (BossHealthPercent < 0.33f) TargetPhase = 3;
	else if (BossHealthPercent < 0.66f) TargetPhase = 2;

	if (TargetPhase != CurrentPhase)
	{
		CurrentPhase = TargetPhase;
		if (OnPhaseTransition.IsBound()) OnPhaseTransition.Broadcast(CurrentPhase);
		UE_LOG(LogTemp, Warning, TEXT("UAshenPsychicEchoPhasedPhaseController: Boss transitioned to PHASE %d (Health: %.1f%%)"), CurrentPhase, BossHealthPercent * 100.0f);
	}
}

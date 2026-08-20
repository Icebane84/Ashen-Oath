// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBossIncursionSubsystem.h"

void UAshenBossIncursionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveBossEncounter.BossId = FName(TEXT("Malakor_The_Sundered_Herald"));
	ActiveBossEncounter.MaxHealth = 10000.0f;
	ActiveBossEncounter.CurrentHealth = 10000.0f;
	ActiveBossEncounter.MaxPoise = 500.0f;
	ActiveBossEncounter.CurrentPoise = 500.0f;
	ActiveBossEncounter.Phase = EBossPhaseState::Phase1_TacticalDuel;
	UE_LOG(LogTemp, Log, TEXT("UAshenBossIncursionSubsystem: Boss Incursion Subsystem Initialized."));
}
void UAshenBossIncursionSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenBossIncursionSubsystem::StartBossEncounter(FName BossId, float MaxHP, float MaxPoise)
{
	ActiveBossEncounter.BossId = BossId;
	ActiveBossEncounter.MaxHealth = MaxHP;
	ActiveBossEncounter.CurrentHealth = MaxHP;
	ActiveBossEncounter.MaxPoise = MaxPoise;
	ActiveBossEncounter.CurrentPoise = MaxPoise;
	ActiveBossEncounter.Phase = EBossPhaseState::Phase1_TacticalDuel;

	UE_LOG(LogTemp, Warning, TEXT("UAshenBossIncursionSubsystem: *** BOSS ENCOUNTER STARTED: %s *** (HP: %.1f, Poise: %.1f)!"),
		*BossId.ToString(), MaxHP, MaxPoise);
}

bool UAshenBossIncursionSubsystem::EvaluatePhaseTransition(float HealthPercent, EBossPhaseState& OutNewPhase)
{
	const float HP = FMath::Clamp(HealthPercent, 0.0f, 1.0f);
	EBossPhaseState TargetPhase = ActiveBossEncounter.Phase;

	if (HP <= 0.0f)
	{
		TargetPhase = EBossPhaseState::Phase_Defeated;
	}
	else if (HP <= 0.35f)
	{
		TargetPhase = EBossPhaseState::Phase3_ApexCataclysm;
	}
	else if (HP <= 0.70f)
	{
		TargetPhase = EBossPhaseState::Phase2_ChasmFracture;
	}
	else
	{
		TargetPhase = EBossPhaseState::Phase1_TacticalDuel;
	}

	const bool bPhaseChanged = (TargetPhase != ActiveBossEncounter.Phase);
	if (bPhaseChanged)
	{
		ActiveBossEncounter.Phase = TargetPhase;
		OutNewPhase = TargetPhase;
		UE_LOG(LogTemp, Error, TEXT("UAshenBossIncursionSubsystem: *** BOSS PHASE TRANSITION -> %d *** (HP: %.1f%%)!"),
			static_cast<int32>(TargetPhase), HP * 100.0f);
	}
	else
	{
		OutNewPhase = ActiveBossEncounter.Phase;
	}

	return bPhaseChanged;
}

void UAshenBossIncursionSubsystem::TriggerBossStagger()
{
	ActiveBossEncounter.Phase = EBossPhaseState::Phase_StaggeredVulnerable;
	ActiveBossEncounter.CurrentPoise = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossIncursionSubsystem: BOSS STAGGERED! Trial of Will 0.75s Execution Window Open!"));
}

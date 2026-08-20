// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 658: Ashen Willpower Reward Matrix Subsystem

#include "AshenWillpowerRewardMatrixSubsystem.h"

void UAshenWillpowerRewardMatrixSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsStateUnbrokenActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenWillpowerRewardMatrixSubsystem: Initialized — Willpower Reward Matrix Subsystem ONLINE."));
}

void UAshenWillpowerRewardMatrixSubsystem::TriggerUnbrokenState()
{
	bIsStateUnbrokenActive = true;
	const float RecoveryBoost = 50.0f; // +50% Stamina Recovery
	const int32 ExtraParryFrames = 3;   // +3 Parry timing frames
	const bool bSmiteRiposte = true;    // Zero-cost Smite Riposte shockwave unlocked

	OnUnbrokenTriggered.Broadcast(RecoveryBoost, ExtraParryFrames, bSmiteRiposte);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWillpowerRewardMatrixSubsystem: STATE.WILLPOWER.UNBROKEN ACTIVE -> Recovery: +%.0f%% | Parry Window: +%d frames | Smite Riposte: UNLOCKED."),
		RecoveryBoost, ExtraParryFrames);
}

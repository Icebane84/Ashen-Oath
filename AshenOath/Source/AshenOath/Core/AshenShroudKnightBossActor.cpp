// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 237: Ashen Shroud-Knight Boss Actor

#include "AshenShroudKnightBossActor.h"

AAshenShroudKnightBossActor::AAshenShroudKnightBossActor()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentState = EAshenShroudKnightState::Physical;
	DitherOpacity = 1.0f;
	bIsAnchoredByConsecratedGround = false;
	bIsPinLockedByKaelen = false;
}

void AAshenShroudKnightBossActor::BeginPlay()
{
	Super::BeginPlay();
}

bool AAshenShroudKnightBossActor::CanPhaseShift() const
{
	if (bIsAnchoredByConsecratedGround)
	{
		UE_LOG(LogTemp, Warning, TEXT("AAshenShroudKnightBossActor: Phase Shift BLOCKED by Serafina's Consecrated Ground!"));
		return false;
	}

	if (bIsPinLockedByKaelen)
	{
		UE_LOG(LogTemp, Warning, TEXT("AAshenShroudKnightBossActor: Phase Shift BLOCKED by Kaelen's Oathbringer Pin-Lock!"));
		return false;
	}

	return CurrentState == EAshenShroudKnightState::Physical;
}

bool AAshenShroudKnightBossActor::TryPhaseShift()
{
	if (!CanPhaseShift()) return false;

	const EAshenShroudKnightState OldState = CurrentState;
	CurrentState = EAshenShroudKnightState::Phasing;
	DitherOpacity = 0.15f; // Translucent spectral outline

	OnStateChanged.Broadcast(OldState, CurrentState);

	UE_LOG(LogTemp, Warning, TEXT("AAshenShroudKnightBossActor: SHROUD-KNIGHT PHASE SHIFTED — Translucency Dither: %.2f."), DitherOpacity);
	return true;
}

void AAshenShroudKnightBossActor::ForcePhysicalAnchor(bool bAnchorActive)
{
	bIsAnchoredByConsecratedGround = bAnchorActive;

	if (bAnchorActive && CurrentState == EAshenShroudKnightState::Phasing)
	{
		const EAshenShroudKnightState OldState = CurrentState;
		CurrentState = EAshenShroudKnightState::Physical;
		DitherOpacity = 1.0f;

		OnStateChanged.Broadcast(OldState, CurrentState);
		UE_LOG(LogTemp, Warning, TEXT("AAshenShroudKnightBossActor: CONSECRATED ANCHOR FORCED SHROUD-KNIGHT PHYSICAL!"));
	}
}

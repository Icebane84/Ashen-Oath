// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 572: Ashen Whisperer Enemy

#include "AshenWhispererEnemy.h"

AAshenWhispererEnemy::AAshenWhispererEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsPhasedIn = true;
}

void AAshenWhispererEnemy::TriggerShadowPhase(bool bPhaseIn)
{
	bIsPhasedIn = bPhaseIn;
	const float SanityDmg = bIsPhasedIn ? 5.0f : 0.0f;

	OnShadowPhaseChanged.Broadcast(bIsPhasedIn, SanityDmg);

	UE_LOG(LogTemp, Warning, TEXT("AAshenWhispererEnemy: WHISPERER SHADOW PHASE -> Phased In: %s (Sanity Dmg/s: %.1f)."),
		bIsPhasedIn ? TEXT("TRUE — Draining Sanity") : TEXT("FALSE — Invisible"), SanityDmg);
}

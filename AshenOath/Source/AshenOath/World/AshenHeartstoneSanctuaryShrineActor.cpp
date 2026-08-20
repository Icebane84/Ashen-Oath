// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 612: Ashen Heartstone Sanctuary Shrine Actor

#include "AshenHeartstoneSanctuaryShrineActor.h"

AAshenHeartstoneSanctuaryShrineActor::AAshenHeartstoneSanctuaryShrineActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsAttuned = false;
	ShrineID = FName(TEXT("Shrine.HeartstoneSanctuary"));
}

void AAshenHeartstoneSanctuaryShrineActor::AttuneToHeartstone(float Power)
{
	bIsAttuned = true;
	OnHeartstoneAttuned.Broadcast(ShrineID, Power);

	UE_LOG(LogTemp, Warning, TEXT("AAshenHeartstoneSanctuaryShrineActor: HEARTSTONE SHRINE ATTUNED -> ID '%s' (Resonance Power: %.0f)."),
		*ShrineID.ToString(), Power);
}

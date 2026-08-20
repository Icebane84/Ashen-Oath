// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCombatTrainingDummyActor.h"

AAshenCombatTrainingDummyActor::AAshenCombatTrainingDummyActor()
{
	PrimaryActorTick.bCanEverTick = false;
	TotalDamageReceived = 0.0f;
	FlankHitsCount = 0;
}
void AAshenCombatTrainingDummyActor::BeginPlay() { Super::BeginPlay(); }

void AAshenCombatTrainingDummyActor::RecordCombatHit(float Damage, bool bWasFlank)
{
	TotalDamageReceived += Damage;
	if (bWasFlank) FlankHitsCount++;

	UE_LOG(LogTemp, Log, TEXT("AAshenCombatTrainingDummyActor: Recorded Hit (Damage: %.1f, Flank: %s, Total DMG: %.1f, Flank Count: %d)"),
		Damage, bWasFlank ? TEXT("TRUE") : TEXT("FALSE"), TotalDamageReceived, FlankHitsCount);
}

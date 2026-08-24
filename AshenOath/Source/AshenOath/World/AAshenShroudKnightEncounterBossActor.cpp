// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenShroudKnightEncounterBossActor.h"
#include "Components/CapsuleComponent.h"

AAshenShroudKnightEncounterBossActor::AAshenShroudKnightEncounterBossActor()
{
	PrimaryActorTick.bCanEverTick = false;

	BossHeightMeters = 2.1f;
	GetCapsuleComponent()->InitCapsuleSize(45.0f, 105.0f);
}

void AAshenShroudKnightEncounterBossActor::BeginPlay()
{
	Super::BeginPlay();
}

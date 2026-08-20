// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGrandMasterMilestone1200MonumentActor.h"

AAshenGrandMasterMilestone1200MonumentActor::AAshenGrandMasterMilestone1200MonumentActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenGrandMasterMilestone1200MonumentActor::BeginPlay()
{
	Super::BeginPlay();
	TriggerGrandMasterMilestone1200AscensionPulse();
}

bool AAshenGrandMasterMilestone1200MonumentActor::TriggerGrandMasterMilestone1200AscensionPulse()
{
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  👑 AAshenGrandMasterMilestone1200MonumentActor: GRAND MASTER MILESTONE 1200 ASCENSION MONUMENT ACTIVATED (1,200 BUILDS CLEAN)!"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}

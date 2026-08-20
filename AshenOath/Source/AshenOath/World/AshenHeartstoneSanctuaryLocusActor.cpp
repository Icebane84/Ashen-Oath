// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenHeartstoneSanctuaryLocusActor.h"

AAshenHeartstoneSanctuaryLocusActor::AAshenHeartstoneSanctuaryLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenHeartstoneSanctuaryLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenHeartstoneSanctuaryLocusActor: Heartstone Sanctuary Locus Actor initialized."));
}

bool AAshenHeartstoneSanctuaryLocusActor::TriggerSanctuaryFlameAuraPulse()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenHeartstoneSanctuaryLocusActor: Triggered white flame sanctuary aura pulse (Intensity: %f)."), WhiteFlameAuraIntensity);
	return true;
}

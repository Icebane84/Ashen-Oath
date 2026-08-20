// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenFloatingMindscapeDebrisActor.h"

AAshenFloatingMindscapeDebrisActor::AAshenFloatingMindscapeDebrisActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFloatingMindscapeDebrisActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenFloatingMindscapeDebrisActor: Mindscape debris actor active."));
}

void AAshenFloatingMindscapeDebrisActor::PulseDebrisOrbit(float BattleIntensity)
{
	FloatSpeed = 1.5f * BattleIntensity;
	UE_LOG(LogTemp, Log, TEXT("AAshenFloatingMindscapeDebrisActor: Debris orbit pulsed at speed %.2f"), FloatSpeed);
}

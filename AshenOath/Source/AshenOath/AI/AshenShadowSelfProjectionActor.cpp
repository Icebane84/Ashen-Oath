// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenShadowSelfProjectionActor.h"

AAshenShadowSelfProjectionActor::AAshenShadowSelfProjectionActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenShadowSelfProjectionActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenShadowSelfProjectionActor: Shadow Self Projection Actor initialized."));
}

bool AAshenShadowSelfProjectionActor::TriggerShadowSelfGaslightingWhispers()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenShadowSelfProjectionActor: Triggered Shadow Self gaslighting whispers in Inner World."));
	return true;
}

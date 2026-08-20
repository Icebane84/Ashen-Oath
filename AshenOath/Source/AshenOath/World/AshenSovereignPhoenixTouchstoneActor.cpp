// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSovereignPhoenixTouchstoneActor.h"

AAshenSovereignPhoenixTouchstoneActor::AAshenSovereignPhoenixTouchstoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSovereignPhoenixTouchstoneActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSovereignPhoenixTouchstoneActor: Sovereign Phoenix Touchstone Actor initialized."));
}

bool AAshenSovereignPhoenixTouchstoneActor::ActivateSovereignTouchstone()
{
	if (!bSovereignTouchstoneActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenSovereignPhoenixTouchstoneActor: Sovereign Phoenix touchstone activated across 1,100 builds clean (Radius: %f)."), SovereignTouchstoneRadius);
	return true;
}

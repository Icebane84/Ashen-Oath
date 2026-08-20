// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenLivingOathAltarActor.h"

AAshenLivingOathAltarActor::AAshenLivingOathAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenLivingOathAltarActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenLivingOathAltarActor: Living Oath Altar active."));
}

bool AAshenLivingOathAltarActor::SwearOathAtAltar(EAshenLivingOathType OathToSwear)
{
	if (!bIsAltarActive) return false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenLivingOathAltarActor: Swore Oath %d at Consecrated Altar!"), (int32)OathToSwear);
	return true;
}

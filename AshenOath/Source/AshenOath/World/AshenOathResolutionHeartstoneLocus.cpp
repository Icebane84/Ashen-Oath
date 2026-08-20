// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenOathResolutionHeartstoneLocus.h"

AAshenOathResolutionHeartstoneLocus::AAshenOathResolutionHeartstoneLocus()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenOathResolutionHeartstoneLocus::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenOathResolutionHeartstoneLocus: Oath Resolution locus active."));
}

bool AAshenOathResolutionHeartstoneLocus::ExecuteNonSkippableOathResolution()
{
	bResolutionPending = false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenOathResolutionHeartstoneLocus: Non-skippable Oath Resolution ritual executed — Oath Burn cleared and stamina recovery unlocked!"));
	return true;
}

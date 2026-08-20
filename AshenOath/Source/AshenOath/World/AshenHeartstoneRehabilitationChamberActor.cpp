// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenHeartstoneRehabilitationChamberActor.h"

AAshenHeartstoneRehabilitationChamberActor::AAshenHeartstoneRehabilitationChamberActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenHeartstoneRehabilitationChamberActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenHeartstoneRehabilitationChamberActor: Rehabilitation Chamber initialized."));
}

bool AAshenHeartstoneRehabilitationChamberActor::BeginIdentitySynthesisRitual()
{
	bRitualInProcess = true;
	if (OnRitualCompleted.IsBound())
	{
		OnRitualCompleted.Broadcast(1.0f);
	}
	bRitualInProcess = false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenHeartstoneRehabilitationChamberActor: Identity Synthesis Ritual completed cleanly!"));
	return true;
}

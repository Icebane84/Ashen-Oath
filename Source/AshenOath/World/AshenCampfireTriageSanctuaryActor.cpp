// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCampfireTriageSanctuaryActor.h"

AAshenCampfireTriageSanctuaryActor::AAshenCampfireTriageSanctuaryActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsTriageSessionActive = false;
}
void AAshenCampfireTriageSanctuaryActor::BeginPlay() { Super::BeginPlay(); }

void AAshenCampfireTriageSanctuaryActor::InitiateRelationalTriage()
{
	bIsTriageSessionActive = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenCampfireTriageSanctuaryActor: Relational Triage Session Initiated at Campfire!"));
}

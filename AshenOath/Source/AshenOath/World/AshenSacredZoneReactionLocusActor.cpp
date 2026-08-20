// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSacredZoneReactionLocusActor.h"

AAshenSacredZoneReactionLocusActor::AAshenSacredZoneReactionLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSacredZoneReactionLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSacredZoneReactionLocusActor: Sacred Zone Reaction Locus initialized."));
}

void AAshenSacredZoneReactionLocusActor::TriggerSacredZoneSanctuaryDialogue()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenSacredZoneReactionLocusActor: Sacred zone sanctuary dialogue triggered!"));
}

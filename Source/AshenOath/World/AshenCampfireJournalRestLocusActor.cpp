// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenCampfireJournalRestLocusActor.h"

AAshenCampfireJournalRestLocusActor::AAshenCampfireJournalRestLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenCampfireJournalRestLocusActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenCampfireJournalRestLocusActor: Campfire Journal Rest Locus Actor initialized."));
}

bool AAshenCampfireJournalRestLocusActor::InitiateCampfireJournalRest(AActor* InstigatorActor)
{
	if (!InstigatorActor || !bCampfireRestActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenCampfireJournalRestLocusActor: Campfire journal rest initiated for %s (Introspection radius: %f)."), *InstigatorActor->GetName(), IntrospectionRadius);
	return true;
}

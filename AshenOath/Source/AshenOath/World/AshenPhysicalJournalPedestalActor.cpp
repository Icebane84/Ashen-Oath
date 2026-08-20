// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenPhysicalJournalPedestalActor.h"

AAshenPhysicalJournalPedestalActor::AAshenPhysicalJournalPedestalActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsJournalPlaced = false;
}
void AAshenPhysicalJournalPedestalActor::BeginPlay() { Super::BeginPlay(); }

void AAshenPhysicalJournalPedestalActor::PlaceJournalOnPedestal(bool bPlaced)
{
	bIsJournalPlaced = bPlaced;
	UE_LOG(LogTemp, Warning, TEXT("AAshenPhysicalJournalPedestalActor: Living Journal %s pedestal!"),
		bIsJournalPlaced ? TEXT("PLACED ON") : TEXT("REMOVED FROM"));
}

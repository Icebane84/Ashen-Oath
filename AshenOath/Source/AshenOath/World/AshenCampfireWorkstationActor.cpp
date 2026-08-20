// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCampfireWorkstationActor.h"

AAshenCampfireWorkstationActor::AAshenCampfireWorkstationActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RestRadius = 500.0f;
	bIsCampfireLit = true;
}
void AAshenCampfireWorkstationActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenCampfireWorkstationActor::InteractWithWorkstation(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenCampfireWorkstationActor: Player interacted with Garrett's Alchemical Workstation."));
	return true;
}

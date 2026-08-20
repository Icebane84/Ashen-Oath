// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenLensSanctuaryPillarActor.h"

AAshenLensSanctuaryPillarActor::AAshenLensSanctuaryPillarActor()
{
	PrimaryActorTick.bCanEverTick = false;
	PillarLens = EInterpretiveLens::Grace;
	bIsPillarActive = false;
}
void AAshenLensSanctuaryPillarActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenLensSanctuaryPillarActor::CommuneWithPillar(AActor* InteractingPlayer)
{
	bIsPillarActive = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenLensSanctuaryPillarActor: Player communed with Sanctuary Pillar (Lens: %d)!"), static_cast<int32>(PillarLens));
	return true;
}

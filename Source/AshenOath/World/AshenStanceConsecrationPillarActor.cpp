// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenStanceConsecrationPillarActor.h"

AAshenStanceConsecrationPillarActor::AAshenStanceConsecrationPillarActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ConsecratedStance = ECombatStance::Flow;
	bIsConsecrated = false;
}
void AAshenStanceConsecrationPillarActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenStanceConsecrationPillarActor::ConsecratePillar(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsConsecrated = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenStanceConsecrationPillarActor: Stance Consecration Pillar unlocked for Stance %d!"),
		static_cast<int32>(ConsecratedStance));
	return true;
}

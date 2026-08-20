// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSerafinaGoldenLeashSanctuaryActor.h"

AAshenSerafinaGoldenLeashSanctuaryActor::AAshenSerafinaGoldenLeashSanctuaryActor()
{
	PrimaryActorTick.bCanEverTick = false;
	TetherRadiusUnits = 600.0f;
}
void AAshenSerafinaGoldenLeashSanctuaryActor::BeginPlay() { Super::BeginPlay(); }

void AAshenSerafinaGoldenLeashSanctuaryActor::EstablishMetaphysicalTether(AActor* SerafinaActor, AActor* KaelenActor)
{
	if (!SerafinaActor || !KaelenActor) return;
	UE_LOG(LogTemp, Warning, TEXT("AAshenSerafinaGoldenLeashSanctuaryActor: METAPHYSICAL TETHER ESTABLISHED between %s and %s (Radius: %.1fuu)!"),
		*SerafinaActor->GetName(), *KaelenActor->GetName(), TetherRadiusUnits);
}

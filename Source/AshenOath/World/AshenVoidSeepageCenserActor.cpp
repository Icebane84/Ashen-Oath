// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenVoidSeepageCenserActor.h"

AAshenVoidSeepageCenserActor::AAshenVoidSeepageCenserActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsCenserActive = true;
}
void AAshenVoidSeepageCenserActor::BeginPlay() { Super::BeginPlay(); }

int32 AAshenVoidSeepageCenserActor::DistillSeepageReagents(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer || !bIsCenserActive) return 0;
	bIsCenserActive = false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenVoidSeepageCenserActor: Distilled 2x Gloomwood Sap reagents."));
	return 2;
}

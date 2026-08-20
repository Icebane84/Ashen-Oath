// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenAlchemicalReagentNodeActor.h"

AAshenAlchemicalReagentNodeActor::AAshenAlchemicalReagentNodeActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ReagentType = EAlchemicalReagent::GloomwoodSap;
	bIsEliteNode = false;
	bIsHarvested = false;
}
void AAshenAlchemicalReagentNodeActor::BeginPlay() { Super::BeginPlay(); }

int32 AAshenAlchemicalReagentNodeActor::HarvestNode(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer || bIsHarvested) return 0;
	bIsHarvested = true;
	const int32 Yield = bIsEliteNode ? 3 : 1;
	UE_LOG(LogTemp, Warning, TEXT("AAshenAlchemicalReagentNodeActor: Harvested %d of Reagent %d."),
		Yield, static_cast<int32>(ReagentType));
	return Yield;
}

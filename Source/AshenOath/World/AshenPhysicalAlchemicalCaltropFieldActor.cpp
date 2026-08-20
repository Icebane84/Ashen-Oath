// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenPhysicalAlchemicalCaltropFieldActor.h"

AAshenPhysicalAlchemicalCaltropFieldActor::AAshenPhysicalAlchemicalCaltropFieldActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsFieldIgnited = false;
}
void AAshenPhysicalAlchemicalCaltropFieldActor::BeginPlay() { Super::BeginPlay(); }

void AAshenPhysicalAlchemicalCaltropFieldActor::TriggerKineticIgnition()
{
	bIsFieldIgnited = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenPhysicalAlchemicalCaltropFieldActor: Caltrop Field Ignited into Thermal Fire!"));
}

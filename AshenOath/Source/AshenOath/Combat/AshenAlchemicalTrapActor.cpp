// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAlchemicalTrapActor.h"

AAshenAlchemicalTrapActor::AAshenAlchemicalTrapActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenAlchemicalTrapActor::BeginPlay()
{
	Super::BeginPlay();
	bIsArmed = true;
	UE_LOG(LogTemp, Log, TEXT("AAshenAlchemicalTrapActor: Alchemical trap actor armed."));
}

void AAshenAlchemicalTrapActor::TriggerTrapDetonation()
{
	if (!bIsArmed) return;
	bIsArmed = false;

	if (OnTrapDetonated.IsBound())
	{
		OnTrapDetonated.Broadcast(GetActorLocation(), 3);
	}
	UE_LOG(LogTemp, Warning, TEXT("AAshenAlchemicalTrapActor: Alchemical trap triggered at (%f, %f, %f)!"),
		GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
}

void AAshenAlchemicalTrapActor::DetonateAlchemicalTrap()
{
	TriggerTrapDetonation();
	Destroy();
}

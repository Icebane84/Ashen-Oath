// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenGloomwoodTripwireActor.h"

AAshenGloomwoodTripwireActor::AAshenGloomwoodTripwireActor()
{
	PrimaryActorTick.bCanEverTick = false;
	TripwireLength = 400.0f;
	bIsArmed = true;
}
void AAshenGloomwoodTripwireActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenGloomwoodTripwireActor::TriggerTripwire(AActor* TargetActor)
{
	if (!TargetActor || !bIsArmed) return false;
	bIsArmed = false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenGloomwoodTripwireActor: Gloomwood Tripwire triggered! Target tripped and spell cast interrupted."));
	return true;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenTacticalAcousticEchoActor.h"

AAshenTacticalAcousticEchoActor::AAshenTacticalAcousticEchoActor()
{
	PrimaryActorTick.bCanEverTick = false;
	AcousticRadius = 800.0f;
}
void AAshenTacticalAcousticEchoActor::BeginPlay() { Super::BeginPlay(); }

float AAshenTacticalAcousticEchoActor::CalculateAcousticOcclusion(const FVector& ListenerLocation) const
{
	const float Dist = FVector::Dist(GetActorLocation(), ListenerLocation);
	const float Occlusion = FMath::Clamp(Dist / AcousticRadius, 0.0f, 1.0f);
	return Occlusion;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenAshCasketPostureBreakerActor.h"

AAshenAshCasketPostureBreakerActor::AAshenAshCasketPostureBreakerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bPostureBroken = false;
}
void AAshenAshCasketPostureBreakerActor::BeginPlay() { Super::BeginPlay(); }

void AAshenAshCasketPostureBreakerActor::BreakAshCasketPosture()
{
	bPostureBroken = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenAshCasketPostureBreakerActor: ASH-CASKET POSTURE BROKEN! Triggering Garrett DualSense Callout: \"Kaelen. Now.\"!"));
}

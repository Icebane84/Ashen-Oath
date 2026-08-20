// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenGarrettTripwireAnchorActor.h"

AAshenGarrettTripwireAnchorActor::AAshenGarrettTripwireAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenGarrettTripwireAnchorActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenGarrettTripwireAnchorActor: Tripwire anchor actor initialized."));
}

void AAshenGarrettTripwireAnchorActor::ArmTripwireAnchor()
{
	bIsAnchored = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenGarrettTripwireAnchorActor: Tripwire anchor ARMED with laser tension!"));
}

bool AAshenGarrettTripwireAnchorActor::DeployTripwireAnchors(FVector StartPos, FVector EndPos)
{
	ArmTripwireAnchor();
	return true;
}

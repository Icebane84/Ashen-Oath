// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenBoneResetSanctuaryAnchorActor.h"

AAshenBoneResetSanctuaryAnchorActor::AAshenBoneResetSanctuaryAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsAnchorChanneling = false;
}
void AAshenBoneResetSanctuaryAnchorActor::BeginPlay() { Super::BeginPlay(); }

void AAshenBoneResetSanctuaryAnchorActor::ChannelGoldenStabilization()
{
	bIsAnchorChanneling = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenBoneResetSanctuaryAnchorActor: Channeling Golden Stabilization Aura for Reclamation!"));
}

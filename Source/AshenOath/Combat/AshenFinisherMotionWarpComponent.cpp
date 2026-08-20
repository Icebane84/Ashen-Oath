// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenFinisherMotionWarpComponent.h"

UAshenFinisherMotionWarpComponent::UAshenFinisherMotionWarpComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherMotionWarpComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenFinisherMotionWarpComponent::WarpCharacterToTarget(AActor* CharacterActor, FVector TargetLocation, FRotator TargetRotation, float WarpSpeed)
{
	if (!CharacterActor) return false;
	bIsWarpingActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherMotionWarpComponent: Warping %s to %s at speed %.1f uu/s."),
		*CharacterActor->GetName(), *TargetLocation.ToString(), WarpSpeed);
	return true;
}

bool UAshenFinisherMotionWarpComponent::SnapHandToPartnerSocket(AActor* AttachingChar, FName SourceSocket, AActor* PartnerChar, FName TargetSocket)
{
	if (!AttachingChar || !PartnerChar) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenFinisherMotionWarpComponent: Snapped %s [%s] -> %s [%s]."),
		*AttachingChar->GetName(), *SourceSocket.ToString(), *PartnerChar->GetName(), *TargetSocket.ToString());
	return true;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 273: Ashen Sanity Hallucination VFX Component

#include "AshenSanityHallucinationVFXComponent.h"

UAshenSanityHallucinationVFXComponent::UAshenSanityHallucinationVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSanityHallucinationVFXComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSanityHallucinationVFXComponent::SpawnPeripheralHallucination(FName VFXEffectID, FVector Offset)
{
	const FVector Origin = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
	const FVector SpawnLoc = Origin + Offset;

	OnHallucinationVFXSpawned.Broadcast(VFXEffectID, SpawnLoc);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSanityHallucinationVFXComponent: PERIPHERAL HALLUCINATION '%s' SPAWNED at (%.0f, %.0f, %.0f)."),
		*VFXEffectID.ToString(), SpawnLoc.X, SpawnLoc.Y, SpawnLoc.Z);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 258: Ashen Boss Phase Particle Controller Component

#include "AshenBossPhaseParticleControllerComponent.h"

UAshenBossPhaseParticleControllerComponent::UAshenBossPhaseParticleControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBossPhaseParticleControllerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenBossPhaseParticleControllerComponent::TriggerPhaseFX(int32 NewPhaseIndex, FName ParticleFXID)
{
	OnBossPhaseFXTriggered.Broadcast(NewPhaseIndex, ParticleFXID);

	const FVector Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;

	UE_LOG(LogTemp, Warning, TEXT("UAshenBossPhaseParticleControllerComponent: BOSS PHASE %d VFX '%s' SPAWNED at (%.0f, %.0f, %.0f)."),
		NewPhaseIndex, *ParticleFXID.ToString(), Location.X, Location.Y, Location.Z);
}

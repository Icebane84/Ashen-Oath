// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "VFX/AshenShadowMarkVFXSubsystem.h"

void UAshenShadowMarkVFXSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	MaxConcurrentParticles = 2048;
	MaxFrustumDistanceUnits = 1500.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenShadowMarkVFXSubsystem: Shadow Mark VFX Subsystem initialized (Cap: 2048 particles, Cull Dist: 1500uu)."));
}
void UAshenShadowMarkVFXSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenShadowMarkVFXSubsystem::ShouldCullSeepageVFX(float DistanceToCamera) const
{
	return (DistanceToCamera > MaxFrustumDistanceUnits);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenShadowMarkCorruptionMPCModulator.h"

void UAshenShadowMarkCorruptionMPCModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenShadowMarkCorruptionMPCModulator: Shadow Mark MPC Modulator initialized."));
}

void UAshenShadowMarkCorruptionMPCModulator::Deinitialize() { Super::Deinitialize(); }

void UAshenShadowMarkCorruptionMPCModulator::UpdateShadowMarkEmissiveScalar(float CorruptionRatio)
{
	ShadowMarkEmissiveIntensity = FMath::Clamp(CorruptionRatio * 5.0f, 0.0f, 5.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenShadowMarkCorruptionMPCModulator: MPC_ShadowMarkC emissive scalar updated to %.2f"), ShadowMarkEmissiveIntensity);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMindscapeOathReactivityMPCModulator.h"

void UAshenMindscapeOathReactivityMPCModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeOathReactivityMPCModulator: Oath Reactivity MPC Modulator initialized."));
}

void UAshenMindscapeOathReactivityMPCModulator::Deinitialize() { Super::Deinitialize(); }

void UAshenMindscapeOathReactivityMPCModulator::UpdateMPCForOathBurden(float OathBurden)
{
	OathCorruptionScalar = FMath::Clamp(OathBurden, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeOathReactivityMPCModulator: MPC_OathCorruption updated to %.2f"), OathCorruptionScalar);
}

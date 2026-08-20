// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 456: Ashen Dynamic Lighting Atmosphere Subsystem

#include "AshenDynamicLightingAtmosphereSubsystem.h"

void UAshenDynamicLightingAtmosphereSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDynamicLightingAtmosphereSubsystem: Initialized — Dynamic Atmosphere Engine ONLINE."));
}

void UAshenDynamicLightingAtmosphereSubsystem::ModulateAtmosphereForCorruption(float ZoneCorruptionPercent)
{
	const float Normalized = FMath::Clamp(ZoneCorruptionPercent / 100.0f, 0.0f, 1.0f);
	const float SunlightIntensity = FMath::Lerp(10.0f, 1.0f, Normalized);
	const FLinearColor FogColor = FLinearColor::LerpUsingHSV(FLinearColor(0.8f, 0.9f, 1.0f), FLinearColor(0.2f, 0.05f, 0.15f), Normalized);

	OnAtmosphereModulated.Broadcast(SunlightIntensity, FogColor);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDynamicLightingAtmosphereSubsystem: ATMOSPHERE MODULATED -> Corruption %.1f%% (Sun Intensity: %.1f)."),
		ZoneCorruptionPercent, SunlightIntensity);
}

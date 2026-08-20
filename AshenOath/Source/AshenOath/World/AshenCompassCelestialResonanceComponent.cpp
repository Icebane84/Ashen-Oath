// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenCompassCelestialResonanceComponent.h"

UAshenCompassCelestialResonanceComponent::UAshenCompassCelestialResonanceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	NeedleBearingDegrees = 0.0f;
	ResonanceState = ECompassResonanceState::Dormant;
}
void UAshenCompassCelestialResonanceComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenCompassCelestialResonanceComponent::CalculateCompassBearing(FVector PlayerLocation, FVector TargetSanctuaryLocation, bool bInNullZone)
{
	if (bInNullZone)
	{
		ResonanceState = ECompassResonanceState::Disrupted;
		NeedleBearingDegrees = FMath::FRandRange(0.0f, 360.0f); // Erratic spinning needle
		UE_LOG(LogTemp, Warning, TEXT("UAshenCompassCelestialResonanceComponent: Null-Zone Magnetic Interference! Needle disrupted."));
		return;
	}

	const FVector Direction = (TargetSanctuaryLocation - PlayerLocation).GetSafeNormal2D();
	const float AngleRad = FMath::Atan2(Direction.Y, Direction.X);
	NeedleBearingDegrees = FMath::RadiansToDegrees(AngleRad);
	if (NeedleBearingDegrees < 0.0f) NeedleBearingDegrees += 360.0f;

	ResonanceState = ECompassResonanceState::Attuned;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompassCelestialResonanceComponent: Sanctuary Beacon Locked! Bearing: %.1f deg"), NeedleBearingDegrees);
}

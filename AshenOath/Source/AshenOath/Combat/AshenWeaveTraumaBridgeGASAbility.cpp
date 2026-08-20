// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenWeaveTraumaBridgeGASAbility.h"

UAshenWeaveTraumaBridgeGASAbility::UAshenWeaveTraumaBridgeGASAbility()
{
	MaxBridgeSpanUnits = 1200.0f;
}

bool UAshenWeaveTraumaBridgeGASAbility::ManifestTraumaBridge(FVector StartLocation, FVector EndLocation)
{
	const float Span = FVector::Dist(StartLocation, EndLocation);
	if (Span > MaxBridgeSpanUnits)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenWeaveTraumaBridgeGASAbility: Bridge span %.1fuu exceeds max %.1fuu!"), Span, MaxBridgeSpanUnits);
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeaveTraumaBridgeGASAbility: TRAUMA LIGHT BRIDGE MANIFESTED! (Span: %.1fuu)!"), Span);
	return true;
}

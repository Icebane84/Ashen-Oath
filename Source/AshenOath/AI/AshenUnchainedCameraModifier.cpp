// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 561: Ashen Unchained Camera Modifier

#include "AshenUnchainedCameraModifier.h"

UAshenUnchainedCameraModifier::UAshenUnchainedCameraModifier()
{
	ActiveFOVOffset = 0.0f;
}

void UAshenUnchainedCameraModifier::TriggerUnchainedFOVShift(float TargetFOV, float Intensity)
{
	ActiveFOVOffset = TargetFOV;
	OnCameraShifted.Broadcast(TargetFOV, Intensity);

	UE_LOG(LogTemp, Log, TEXT("UAshenUnchainedCameraModifier: UNCHAINED CAMERA SHIFT -> Target FOV: %.1f | Intensity: %.2f."),
		TargetFOV, Intensity);
}

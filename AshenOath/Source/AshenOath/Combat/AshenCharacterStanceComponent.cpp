// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 541: Ashen Character Stance Component

#include "AshenCharacterStanceComponent.h"

UAshenCharacterStanceComponent::UAshenCharacterStanceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStanceTag = FName(TEXT("Stance.Steady"));
	GuardBlendWeight = 0.5f;
}

void UAshenCharacterStanceComponent::UpdateStanceFromResolve(float ResolveValue)
{
	const float Normalized = FMath::Clamp(ResolveValue / 100.0f, 0.0f, 1.0f);
	GuardBlendWeight = 1.0f - Normalized;

	if (Normalized >= 0.7f)
	{
		CurrentStanceTag = FName(TEXT("Stance.UprightGrounded"));
	}
	else if (Normalized <= 0.3f)
	{
		CurrentStanceTag = FName(TEXT("Stance.HunchedGuarded"));
	}
	else
	{
		CurrentStanceTag = FName(TEXT("Stance.Steady"));
	}

	OnStanceUpdated.Broadcast(CurrentStanceTag, GuardBlendWeight);

	UE_LOG(LogTemp, Log, TEXT("UAshenCharacterStanceComponent: Stance Updated -> '%s' (Guard Blend Weight: %.2f)."),
		*CurrentStanceTag.ToString(), GuardBlendWeight);
}

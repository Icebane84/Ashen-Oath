// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenLuminousAegisNetComponent.h"

UAshenLuminousAegisNetComponent::UAshenLuminousAegisNetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsNetActive = false;
	PoiseAbsorptionPercentage = 0.75f;
	RemainingPoiseBreakShields = 2;
}
void UAshenLuminousAegisNetComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenLuminousAegisNetComponent::AbsorbPoiseStrike(float IncomingPoiseDamage, float& OutAbsorbedPoise, bool& bDidThreadSnap)
{
	if (!bIsNetActive || RemainingPoiseBreakShields <= 0)
	{
		OutAbsorbedPoise = 0.0f;
		bDidThreadSnap = false;
		return false;
	}

	OutAbsorbedPoise = IncomingPoiseDamage * PoiseAbsorptionPercentage;
	RemainingPoiseBreakShields--;
	bDidThreadSnap = true;

	if (RemainingPoiseBreakShields == 0)
	{
		bIsNetActive = false;
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenLuminousAegisNetComponent: AEGIS NET ABSORBED %.1f POISE! (Remaining Shields: %d)"),
		OutAbsorbedPoise, RemainingPoiseBreakShields);
	return true;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTransferenceCatharsisComponent.h"

UAshenTransferenceCatharsisComponent::UAshenTransferenceCatharsisComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PyreAetherPurity = 0.0f;
	BurnoutReliefScalar = 0.50f;
}
void UAshenTransferenceCatharsisComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenTransferenceCatharsisComponent::TransmuteSapToAether(float CurrentBurnout, float& OutNewBurnout)
{
	PyreAetherPurity = 1.0f;
	OutNewBurnout = FMath::Clamp(CurrentBurnout * (1.0f - BurnoutReliefScalar), 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("UAshenTransferenceCatharsisComponent: EXOTHERMIC PYRE-AETHER TRANSMUTATION! (Burnout: %.2f -> %.2f)"),
		CurrentBurnout, OutNewBurnout);
	return true;
}

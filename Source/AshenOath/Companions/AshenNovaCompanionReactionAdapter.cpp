// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenNovaCompanionReactionAdapter.h"

UAshenNovaCompanionReactionAdapter::UAshenNovaCompanionReactionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNovaCompanionReactionAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenNovaCompanionReactionAdapter::CalculateSerafinaHandTremorOffset(float EmpathicBurnout) const
{
	// Procedural tremor offset amplitude in cm (0.0 up to 3.5cm at 100% burnout)
	const float Amplitude = FMath::Clamp(EmpathicBurnout, 0.0f, 1.0f) * 3.5f;
	return Amplitude;
}

FName UAshenNovaCompanionReactionAdapter::GetGarrettPerimeterStance() const
{
	return FName(TEXT("Stance.Garrett.NovaPerimeterShield"));
}

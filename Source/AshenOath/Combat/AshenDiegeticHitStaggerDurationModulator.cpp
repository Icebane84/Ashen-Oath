// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenDiegeticHitStaggerDurationModulator.h"

UAshenDiegeticHitStaggerDurationModulator::UAshenDiegeticHitStaggerDurationModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticHitStaggerDurationModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	StaggerDurationScalar = FMath::Clamp(1.2f - (NewState.Resolve * 0.4f), 0.8f, 1.4f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticHitStaggerDurationModulator: Stagger duration scalar set to %.2f"), StaggerDurationScalar);
}

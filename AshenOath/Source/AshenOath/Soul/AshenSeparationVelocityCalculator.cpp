// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 621: Ashen Separation Velocity Calculator

#include "AshenSeparationVelocityCalculator.h"

void UAshenSeparationVelocityCalculator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveSeparationVelocity = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenSeparationVelocityCalculator: Initialized — Separation Velocity Calculator ONLINE."));
}

float UAshenSeparationVelocityCalculator::CalculateSeparationVelocity(float IntegrationDebt, float UnresolvedTraumaCount)
{
	ActiveSeparationVelocity = FMath::Clamp(IntegrationDebt * 1.5f + (UnresolvedTraumaCount * 0.2f), 0.0f, 5.0f);
	const float RelationalDivergenceRate = ActiveSeparationVelocity * 0.8f;

	OnVelocityCalculated.Broadcast(ActiveSeparationVelocity, RelationalDivergenceRate);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSeparationVelocityCalculator: SEPARATION VELOCITY CALCULATED -> Velocity: %.2f | Divergence Rate: %.2f."),
		ActiveSeparationVelocity, RelationalDivergenceRate);

	return ActiveSeparationVelocity;
}

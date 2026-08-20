// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionMoraleDissonanceModulator.h"

UAshenCompanionMoraleDissonanceModulator::UAshenCompanionMoraleDissonanceModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionMoraleDissonanceModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	CompanionAggressionScalar = FMath::Clamp(1.0f - (NewState.IntegrationDebt * 0.5f), 0.5f, 1.3f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionMoraleDissonanceModulator: Companion aggression scalar set to %.2f"), CompanionAggressionScalar);
}

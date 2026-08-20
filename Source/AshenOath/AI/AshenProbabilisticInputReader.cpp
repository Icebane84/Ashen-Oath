// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenProbabilisticInputReader.h"

UAshenProbabilisticInputReader::UAshenProbabilisticInputReader()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenProbabilisticInputReader::BeginPlay()
{
	Super::BeginPlay();
}

float UAshenProbabilisticInputReader::CalculateReactionProbability(float TargetDistance, float StaminaReserve, float AggressionWeight)
{
	float StaminaFactor = FMath::Clamp(1.0f - (StaminaReserve / 100.0f), 0.1f, 1.0f);
	float DistanceDecay = FMath::Exp(-0.002f * TargetDistance);
	float P_React = BaseProbability * StaminaFactor * AggressionWeight * DistanceDecay;
	UE_LOG(LogTemp, Log, TEXT("UAshenProbabilisticInputReader: Calculated probabilistic reaction P_react = %f"), P_React);
	return P_React;
}

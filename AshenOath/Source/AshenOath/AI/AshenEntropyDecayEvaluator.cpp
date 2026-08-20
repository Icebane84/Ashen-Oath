// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenEntropyDecayEvaluator.h"

UAshenEntropyDecayEvaluator::UAshenEntropyDecayEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenEntropyDecayEvaluator::BeginPlay()
{
	Super::BeginPlay();
}

float UAshenEntropyDecayEvaluator::CalculateDecayedUtility(float BaseUtility, int32 RecentUsageCount)
{
	float DecayFactor = FMath::Max(0.0f, 1.0f - (EntropyGamma * RecentUsageCount));
	float DecayedUtility = BaseUtility * DecayFactor;
	UE_LOG(LogTemp, Log, TEXT("UAshenEntropyDecayEvaluator: LAW-041 Decay applied (Base: %f, Recent: %d, Decayed: %f)"), BaseUtility, RecentUsageCount, DecayedUtility);
	return DecayedUtility;
}

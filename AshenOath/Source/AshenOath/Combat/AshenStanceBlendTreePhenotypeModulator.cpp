// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenStanceBlendTreePhenotypeModulator.h"

UAshenStanceBlendTreePhenotypeModulator::UAshenStanceBlendTreePhenotypeModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenStanceBlendTreePhenotypeModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	StanceBlendWeight = FMath::Clamp((NewState.Corruption * 0.5f) + ((1.0f - NewState.Resolve) * 0.5f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenStanceBlendTreePhenotypeModulator: Combat stance animation blend weight updated to %.2f"), StanceBlendWeight);
}

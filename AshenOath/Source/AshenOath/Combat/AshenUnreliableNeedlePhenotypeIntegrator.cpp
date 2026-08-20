// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNeedlePhenotypeIntegrator.h"

UAshenUnreliableNeedlePhenotypeIntegrator::UAshenUnreliableNeedlePhenotypeIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNeedlePhenotypeIntegrator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	PerceptionNoise = FMath::Clamp(NewState.Isolation * 0.8f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNeedlePhenotypeIntegrator: Perception noise updated to %.2f"), PerceptionNoise);
}

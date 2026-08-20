// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeWorldPhenotypeIntegrator.h"

UAshenGenerativeWorldPhenotypeIntegrator::UAshenGenerativeWorldPhenotypeIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeWorldPhenotypeIntegrator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	WeatherTension = FMath::Clamp((NewState.Corruption * 0.7f) + ((1.0f - NewState.Resolve) * 0.3f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeWorldPhenotypeIntegrator: Integrated weather tension -> %.2f"), WeatherTension);
}

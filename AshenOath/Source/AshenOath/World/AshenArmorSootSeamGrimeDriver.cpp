// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenArmorSootSeamGrimeDriver.h"

UAshenArmorSootSeamGrimeDriver::UAshenArmorSootSeamGrimeDriver()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenArmorSootSeamGrimeDriver::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenArmorSootSeamGrimeDriver::ApplyArmorSootParameters(float SootMask, float SeamGrimeMask)
{
	CurrentRoughnessScalar = FMath::Lerp(0.20f, 0.85f, SootMask);
	UE_LOG(LogTemp, Log, TEXT("UAshenArmorSootSeamGrimeDriver: Applied armor soot shader parameters (Roughness: %f)"), CurrentRoughnessScalar);
}

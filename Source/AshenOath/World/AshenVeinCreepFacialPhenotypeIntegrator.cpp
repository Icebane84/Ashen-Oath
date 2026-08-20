// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenVeinCreepFacialPhenotypeIntegrator.h"

UAshenVeinCreepFacialPhenotypeIntegrator::UAshenVeinCreepFacialPhenotypeIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenVeinCreepFacialPhenotypeIntegrator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	VeinCreepScalar = FMath::Clamp(NewState.Corruption, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenVeinCreepFacialPhenotypeIntegrator: Integrated vein creep scalar -> %.2f"), VeinCreepScalar);
}

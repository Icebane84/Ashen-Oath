// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticVeinCreepModulator.h"

UAshenSomaticVeinCreepModulator::UAshenSomaticVeinCreepModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticVeinCreepModulator::UpdateVeinCreep(float Corruption)
{
	VeinCreepScalar = FMath::Clamp(Corruption, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticVeinCreepModulator: Vein creep progress updated to %.2f"), VeinCreepScalar);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenDiegeticArmorCrackleAudioModulator.h"

UAshenDiegeticArmorCrackleAudioModulator::UAshenDiegeticArmorCrackleAudioModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticArmorCrackleAudioModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ArmorCrackleVolumeMultiplier = 1.0f + (NewState.Corruption * 0.75f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticArmorCrackleAudioModulator: Armor crackle volume multiplier set to %.2f"), ArmorCrackleVolumeMultiplier);
}

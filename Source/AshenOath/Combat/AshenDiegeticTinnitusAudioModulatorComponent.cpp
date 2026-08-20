// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenDiegeticTinnitusAudioModulatorComponent.h"

UAshenDiegeticTinnitusAudioModulatorComponent::UAshenDiegeticTinnitusAudioModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticTinnitusAudioModulatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	TinnitusWhineVolume = (NewState.Corruption > 0.7f) ? (NewState.Corruption - 0.7f) * 3.33f : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticTinnitusAudioModulatorComponent: Tinnitus whine volume set to %.2f"), TinnitusWhineVolume);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 761: Ashen Blackwood Corrupted Mist Volume Component

#include "AshenBlackwoodCorruptedMistVolumeComponent.h"

UAshenBlackwoodCorruptedMistVolumeComponent::UAshenBlackwoodCorruptedMistVolumeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveMistDensity = 80.0f;
}

void UAshenBlackwoodCorruptedMistVolumeComponent::UpdateMistDensity(float NewDensityPercent)
{
	ActiveMistDensity = FMath::Clamp(NewDensityPercent, 0.0f, 100.0f);
	const float VisPenalty = ActiveMistDensity * 0.5f;

	OnMistUpdated.Broadcast(ActiveMistDensity, VisPenalty);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBlackwoodCorruptedMistVolumeComponent: MIST DENSITY UPDATED -> Density: %.1f%% | Visibility Penalty: -%.1f%%."),
		ActiveMistDensity, VisPenalty);
}

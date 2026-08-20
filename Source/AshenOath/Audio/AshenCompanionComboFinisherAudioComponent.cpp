// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 448: Ashen Companion Combo Finisher Audio Component

#include "AshenCompanionComboFinisherAudioComponent.h"

UAshenCompanionComboFinisherAudioComponent::UAshenCompanionComboFinisherAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionComboFinisherAudioComponent::TriggerFinisherVoiceBark(FName CompanionID, FName AudioBarkTag)
{
	if (CompanionID.IsNone()) return;

	OnFinisherAudioTriggered.Broadcast(CompanionID, AudioBarkTag);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionComboFinisherAudioComponent: FINISHER VOICE BARK TRIGGERED -> Companion '%s' [%s]."),
		*CompanionID.ToString(), *AudioBarkTag.ToString());
}

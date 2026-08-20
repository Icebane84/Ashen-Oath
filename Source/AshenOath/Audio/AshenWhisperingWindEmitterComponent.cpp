// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 573: Ashen Whispering Wind Emitter Component

#include "AshenWhisperingWindEmitterComponent.h"

UAshenWhisperingWindEmitterComponent::UAshenWhisperingWindEmitterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalWhispersEmitted = 0;
}

void UAshenWhisperingWindEmitterComponent::EmitWhisperCue(FName DialogueCueID, float PitchShift)
{
	TotalWhispersEmitted++;
	OnWhisperEmitted.Broadcast(DialogueCueID, PitchShift);

	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingWindEmitterComponent: WHISPER CUE EMITTED -> '%s' (Pitch: %.2f | Total: %d)."),
		*DialogueCueID.ToString(), PitchShift, TotalWhispersEmitted);
}

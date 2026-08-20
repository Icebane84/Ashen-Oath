// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticAudioRoutingSubsystem.h"

void UAshenDiegeticAudioRoutingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bControllerSpeakerEnabled = true;
	bHeadphoneDownmixActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAudioRoutingSubsystem: Proximity of Consciousness Audio Subsystem initialized."));
}
void UAshenDiegeticAudioRoutingSubsystem::Deinitialize() { Super::Deinitialize(); }

EAudioConsciousnessChannel UAshenDiegeticAudioRoutingSubsystem::ResolveEffectiveChannel(EAudioConsciousnessChannel RequestedChannel) const
{
	// Accessibility Rule: If controller speaker is disabled or headphone downmix is on, fallback to World/Headphones
	if (RequestedChannel == EAudioConsciousnessChannel::PersonalAction && !bControllerSpeakerEnabled)
	{
		return EAudioConsciousnessChannel::WorldSpatial;
	}
	if (bHeadphoneDownmixActive && RequestedChannel == EAudioConsciousnessChannel::PersonalAction)
	{
		return EAudioConsciousnessChannel::InternalSomatic;
	}
	return RequestedChannel;
}

void UAshenDiegeticAudioRoutingSubsystem::DispatchVoiceCue(const FDualSenseVoiceCue& Cue)
{
	const EAudioConsciousnessChannel EffectiveChannel = ResolveEffectiveChannel(Cue.TargetChannel);
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticAudioRoutingSubsystem: Dispatched Voice Cue [%s -> Channel %d]: \"%s\" (Tactical: %s)"),
		*Cue.SpeakerID.ToString(), static_cast<int32>(EffectiveChannel), *Cue.SpokenLine, Cue.bIsActionableTacticalTiming ? TEXT("TRUE") : TEXT("FALSE"));
}

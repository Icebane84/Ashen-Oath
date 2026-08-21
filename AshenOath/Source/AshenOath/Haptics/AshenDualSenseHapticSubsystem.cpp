// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Haptics/AshenDualSenseHapticSubsystem.h"

UAshenDualSenseHapticSubsystem::UAshenDualSenseHapticSubsystem()
{
}

void UAshenDualSenseHapticSubsystem::ApplyTriggerConfig(bool bIsLeftTrigger, const FDualSenseTriggerConfig& Config)
{
	if (bIsLeftTrigger)
	{
		LeftConfig = Config;
	}
	else
	{
		RightConfig = Config;
	}

	OnTriggerConfigChanged.Broadcast(bIsLeftTrigger, Config);
}

void UAshenDualSenseHapticSubsystem::RouteTactileWhisper(const FTactileWhisperPayload& Payload)
{
	OnTactileWhisperEmitted.Broadcast(Payload);
}

void UAshenDualSenseHapticSubsystem::PulseDirectionalHaptics(float LeftIntensity, float RightIntensity)
{
	const float ClampedL = FMath::Clamp(LeftIntensity, 0.0f, 1.0f);
	const float ClampedR = FMath::Clamp(RightIntensity, 0.0f, 1.0f);
	OnDirectionalTactilePulse.Broadcast(ClampedL, ClampedR);
}

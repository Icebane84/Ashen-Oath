// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenSpireAudioSubsystem.h"

UAshenSpireAudioSubsystem::UAshenSpireAudioSubsystem()
{
}

float UAshenSpireAudioSubsystem::EvaluateWireSnapPitch(float TensionScalar) const
{
	// High tension = sharp mechanical snap pitch (up to 1200 Hz)
	return FMath::Clamp(400.0f + (TensionScalar * 800.0f), 400.0f, 1200.0f);
}

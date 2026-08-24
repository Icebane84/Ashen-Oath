// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenQuartzMetaSoundsGraphAdapter.h"

UAshenQuartzMetaSoundsGraphAdapter::UAshenQuartzMetaSoundsGraphAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenQuartzMetaSoundsGraphAdapter::FormatMetaSoundsGainParam(float LinearGain) const
{
	return FMath::Clamp(LinearGain, 0.0f, 1.0f);
}

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCognitiveFracturePostProcessAdapter.h"

UAshenCognitiveFracturePostProcessAdapter::UAshenCognitiveFracturePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCognitiveFracturePostProcessAdapter::EvaluateFracturePostProcess(
	float DissonanceIndex,
	float& OutSpectralGhosting,
	float& OutMemoryFilmGrain,
	float& OutEdgeDarkening) const
{
	const float SafeD = FMath::Clamp(DissonanceIndex, 0.0f, 1.0f);

	if (SafeD > 0.50f)
	{
		const float Excess = (SafeD - 0.50f) / 0.50f;
		OutSpectralGhosting = Excess * 0.75f;
		OutMemoryFilmGrain = Excess * 0.60f;
		OutEdgeDarkening = 0.20f + (Excess * 0.65f);
	}
	else
	{
		OutSpectralGhosting = 0.0f;
		OutMemoryFilmGrain = 0.0f;
		OutEdgeDarkening = 0.10f;
	}
}

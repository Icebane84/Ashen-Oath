// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMasonryCollapsePostProcessAdapter.h"

UAshenMasonryCollapsePostProcessAdapter::UAshenMasonryCollapsePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMasonryCollapsePostProcessAdapter::EvaluateCollapsePostProcess(
	EMasonryCollapseState CollapseState,
	float& OutCameraShakeAmplitude,
	float& OutDustFogDensity,
	float& OutRadialBlur)
{
	switch (CollapseState)
	{
	case EMasonryCollapseState::CollapsingImpact:
		OutCameraShakeAmplitude = 1.0f;
		OutDustFogDensity = 0.85f;
		OutRadialBlur = 0.60f;
		break;
	case EMasonryCollapseState::TelegraphWarning:
		OutCameraShakeAmplitude = 0.15f;
		OutDustFogDensity = 0.25f;
		OutRadialBlur = 0.0f;
		break;
	case EMasonryCollapseState::SettledDebrisPile:
		OutCameraShakeAmplitude = 0.0f;
		OutDustFogDensity = 0.40f;
		OutRadialBlur = 0.0f;
		break;
	case EMasonryCollapseState::StressGroaning:
	case EMasonryCollapseState::StableIntact:
	default:
		OutCameraShakeAmplitude = 0.0f;
		OutDustFogDensity = 0.0f;
		OutRadialBlur = 0.0f;
		break;
	}
}

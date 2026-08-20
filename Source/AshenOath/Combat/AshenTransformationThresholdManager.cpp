// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenTransformationThresholdManager.h"

UAshenTransformationThresholdManager::UAshenTransformationThresholdManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTransformationThresholdManager::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenTransformationThresholdManager::EvaluateTransformationCurves(float RawCorruption)
{
	EAshenDualityState TargetState = EAshenDualityState::LightMode;

	if (RawCorruption >= 0.90f)
	{
		TargetState = EAshenDualityState::FullDarkMode;
	}
	else if (RawCorruption >= 0.35f)
	{
		TargetState = EAshenDualityState::TransitionPhase2;
	}
	else if (RawCorruption > 0.05f)
	{
		TargetState = EAshenDualityState::TransitionPhase1;
	}

	if (CurrentDualityState != TargetState)
	{
		EAshenDualityState PrevState = CurrentDualityState;
		CurrentDualityState = TargetState;
		if (OnDualityStateShifted.IsBound())
		{
			OnDualityStateShifted.Broadcast(PrevState, CurrentDualityState);
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenTransformationThresholdManager: Duality transformation state shifted to %d"), static_cast<int32>(CurrentDualityState));
	}
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenInnerWorldLandscapeSubsystem.h"

void UAshenInnerWorldLandscapeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenInnerWorldLandscapeSubsystem: Initialized Inner World Landscape Subsystem."));
}

void UAshenInnerWorldLandscapeSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenInnerWorldLandscapeSubsystem::EvaluateLandscapeStateFromSoulVector(float HopeScore, float DespairScore, float IntegrationDebt)
{
	EAshenInnerWorldLandscapeState TargetState = EAshenInnerWorldLandscapeState::SunDappledGlade;

	if (IntegrationDebt >= 0.80f)
	{
		TargetState = EAshenInnerWorldLandscapeState::CrumblingFortress;
	}
	else if (DespairScore > HopeScore)
	{
		TargetState = EAshenInnerWorldLandscapeState::ShadowedRuinedHamlet;
	}
	else if (HopeScore >= 0.70f)
	{
		TargetState = EAshenInnerWorldLandscapeState::SacredMemorialGlade;
	}

	if (CurrentLandscapeState != TargetState)
	{
		EAshenInnerWorldLandscapeState PrevState = CurrentLandscapeState;
		CurrentLandscapeState = TargetState;
		if (OnInnerWorldLandscapeShifted.IsBound())
		{
			OnInnerWorldLandscapeShifted.Broadcast(PrevState, CurrentLandscapeState);
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenInnerWorldLandscapeSubsystem: Inner World metaphysical landscape shifted to %d"), static_cast<int32>(CurrentLandscapeState));
	}
}

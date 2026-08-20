// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/AshenSomaticAIDirectorComponent.h"
#include "Engine/World.h"

UAshenSomaticAIDirectorComponent::UAshenSomaticAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	UpwardAlertThreshold = 0.30f;
	DownwardRelaxThreshold = 0.18f;
	MinStateDwellSeconds = 3.0f;
	BarkCooldownSeconds = 8.0f;
	StandardSpacingUU = 600.0f;
	TightSupportedSpacingUU = 250.0f;
	bInHighAlertFormation = false;
	LastStateTransitionTime = 0.0;
	LastBarkTimestamp = 0.0;
}

void UAshenSomaticAIDirectorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAshenSomaticAIDirectorComponent::UpdateSomaticState(const FSomaticState& SomaticState)
{
	CurrentSomaticState = SomaticState;
	const double CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;

	// Calculate compound stress metric (Internal Friction modified by Isolation)
	const float CompoundStress = (SomaticState.InternalFriction * 0.70f) + (SomaticState.IsolationPressure * 0.30f);

	const bool bDwellElapsed = (CurrentTime - LastStateTransitionTime) >= MinStateDwellSeconds;

	if (!bInHighAlertFormation)
	{
		if (CompoundStress >= UpwardAlertThreshold && bDwellElapsed)
		{
			bInHighAlertFormation = true;
			LastStateTransitionTime = CurrentTime;
		}
	}
	else
	{
		if (CompoundStress <= DownwardRelaxThreshold && bDwellElapsed)
		{
			bInHighAlertFormation = false;
			LastStateTransitionTime = CurrentTime;
		}
	}
}

float UAshenSomaticAIDirectorComponent::GetRecommendedFormationSpacing() const
{
	// Supported struggle (High Friction + High Flow) tightens formation dramatically
	if (CurrentSomaticState.InternalFriction >= 0.80f && CurrentSomaticState.RelationalFlow >= 0.75f)
	{
		return TightSupportedSpacingUU;
	}

	if (bInHighAlertFormation)
	{
		return FMath::Lerp(StandardSpacingUU, TightSupportedSpacingUU, CurrentSomaticState.InternalFriction);
	}

	return StandardSpacingUU;
}

bool UAshenSomaticAIDirectorComponent::CanTriggerPredictiveBark(double CurrentTimeSeconds)
{
	if ((CurrentTimeSeconds - LastBarkTimestamp) >= BarkCooldownSeconds)
	{
		LastBarkTimestamp = CurrentTimeSeconds;
		return true;
	}
	return false;
}

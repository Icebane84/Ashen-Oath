// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenRhythmicBreathingCadenceComponent.h"

UAshenRhythmicBreathingCadenceComponent::UAshenRhythmicBreathingCadenceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentCadence.bExpectingInhale = true;
	CurrentCadence.BreathBPM = 45.0f;
	CurrentCadence.ConsecutiveSuccessfulBreaths = 0;
}
void UAshenRhythmicBreathingCadenceComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenRhythmicBreathingCadenceComponent::RegisterBreathInput(bool bIsInhaleInput)
{
	if (bIsInhaleInput == CurrentCadence.bExpectingInhale)
	{
		CurrentCadence.ConsecutiveSuccessfulBreaths++;
		CurrentCadence.bExpectingInhale = !CurrentCadence.bExpectingInhale; // Flip expectation

		UE_LOG(LogTemp, Log, TEXT("UAshenRhythmicBreathingCadenceComponent: Clean Breath -> Next Expecting: %s (Streak: %d)"),
			CurrentCadence.bExpectingInhale ? TEXT("INHALE (Cross)") : TEXT("EXHALE (Square)"), CurrentCadence.ConsecutiveSuccessfulBreaths);
		return true;
	}

	CurrentCadence.ConsecutiveSuccessfulBreaths = 0;
	UE_LOG(LogTemp, Warning, TEXT("UAshenRhythmicBreathingCadenceComponent: MISTIMED BREATH! Streak reset."));
	return false;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 314: Ashen Sanity Break Events Component

#include "AshenSanityBreakEventsComponent.h"

UAshenSanityBreakEventsComponent::UAshenSanityBreakEventsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SanityBreakThreshold = 15.0f;
	bBreakActive = false;
}

void UAshenSanityBreakEventsComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSanityBreakEventsComponent::EvaluateSanityForBreak(float CurrentSanity, float MaxSanity)
{
	if (MaxSanity <= 0.0f) return;

	const float Pct = (CurrentSanity / MaxSanity) * 100.0f;

	if (Pct <= SanityBreakThreshold && !bBreakActive)
	{
		bBreakActive = true;
		EAshenSanityBreakType BreakType = EAshenSanityBreakType::ParalyticTerror;

		OnSanityBreakTriggered.Broadcast(BreakType, 4.0f);

		UE_LOG(LogTemp, Warning, TEXT("UAshenSanityBreakEventsComponent: PSYCHOLOGICAL SANITY BREAK TRIGGERED — Type %d (Sanity: %.1f%%)."),
			(int32)BreakType, Pct);
	}
	else if (Pct > SanityBreakThreshold)
	{
		bBreakActive = false;
	}
}

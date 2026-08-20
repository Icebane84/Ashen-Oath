// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenJournalHandwritingMorphComponent.h"

UAshenJournalHandwritingMorphComponent::UAshenJournalHandwritingMorphComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenJournalHandwritingMorphComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenJournalHandwritingMorphComponent::CalculateHandwritingDegradation(float KaelenDebt)
{
	if (KaelenDebt > 0.75f)
	{
		LetterJitterFrequency = (KaelenDebt - 0.75f) * 10.0f; // Rapid shaking
		PenPressureScale = 2.5f; // White-knuckled pressure & fiber tearing
	}
	else
	{
		LetterJitterFrequency = 0.0f;
		PenPressureScale = 1.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenJournalHandwritingMorphComponent: Handwriting degradation calculated — Jitter: %.2f | Pressure: %.2f"),
		LetterJitterFrequency, PenPressureScale);
}

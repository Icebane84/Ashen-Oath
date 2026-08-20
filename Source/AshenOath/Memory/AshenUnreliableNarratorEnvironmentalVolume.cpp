// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenUnreliableNarratorEnvironmentalVolume.h"

AAshenUnreliableNarratorEnvironmentalVolume::AAshenUnreliableNarratorEnvironmentalVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenUnreliableNarratorEnvironmentalVolume::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenUnreliableNarratorEnvironmentalVolume: Hallucination volume active."));
}

void AAshenUnreliableNarratorEnvironmentalVolume::EvaluateSanityDistortion(float SanityLevel, float DebtLevel)
{
	if (SanityLevel < 0.15f || DebtLevel > 0.85f)
	{
		CurrentHallucinationState = EAshenEnvironmentalHallucinationState::Reality_Collapsed;
	}
	else if (SanityLevel < 0.30f || DebtLevel > 0.60f)
	{
		CurrentHallucinationState = EAshenEnvironmentalHallucinationState::Warped_Labyrinth;
	}
	else if (SanityLevel < 0.50f || DebtLevel > 0.40f)
	{
		CurrentHallucinationState = EAshenEnvironmentalHallucinationState::Flickering_Slight;
	}
	else
	{
		CurrentHallucinationState = EAshenEnvironmentalHallucinationState::Default_Coherent;
	}

	if (OnHallucinationChanged.IsBound())
	{
		OnHallucinationChanged.Broadcast(CurrentHallucinationState);
	}

	UE_LOG(LogTemp, Warning, TEXT("AAshenUnreliableNarratorEnvironmentalVolume: Hallucination state evaluated to enum %d (Sanity: %.2f | Debt: %.2f)"),
		(int32)CurrentHallucinationState, SanityLevel, DebtLevel);
}

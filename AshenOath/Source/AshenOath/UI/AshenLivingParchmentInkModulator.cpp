// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenLivingParchmentInkModulator.h"

UAshenLivingParchmentInkModulator::UAshenLivingParchmentInkModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingParchmentInkModulator::BeginPlay() { Super::BeginPlay(); }

float UAshenLivingParchmentInkModulator::CalculateSootVignette(EJournalPerspectiveType Perspective) const
{
	if (Perspective == EJournalPerspectiveType::SolitaryMartyrdom)
	{
		return 0.85f; // Heavy burnt soot vignette around page borders
	}
	return 0.10f; // Clean, warm parchment
}

float UAshenLivingParchmentInkModulator::CalculateTearStainOpacity(EJournalPerspectiveType Perspective) const
{
	if (Perspective == EJournalPerspectiveType::SolitaryMartyrdom)
	{
		return 0.75f; // Visible smeared water/tear stain from Serafina
	}
	return 0.0f;
}

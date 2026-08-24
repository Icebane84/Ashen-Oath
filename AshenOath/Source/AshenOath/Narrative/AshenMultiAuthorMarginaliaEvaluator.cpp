// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenMultiAuthorMarginaliaEvaluator.h"

UAshenMultiAuthorMarginaliaEvaluator::UAshenMultiAuthorMarginaliaEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenMultiAuthorMarginaliaEvaluator::IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor Author, float TrustScore01) const
{
	const float SafeTrust = FMath::Clamp(TrustScore01, 0.0f, 1.0f);

	switch (Author)
	{
	case EForensicMarginaliaAuthor::SystemCanon:
		return true; // Always visible
	case EForensicMarginaliaAuthor::Kaelen:
		return true; // Protagonist baseline
	case EForensicMarginaliaAuthor::Garrett:
		return SafeTrust >= 0.40f; // Unlocks at 40% trust
	case EForensicMarginaliaAuthor::Serafina:
		return SafeTrust >= 0.70f; // Unlocks at 70% trust
	default:
		return true;
	}
}

FLinearColor UAshenMultiAuthorMarginaliaEvaluator::GetAuthorInkColor(EForensicMarginaliaAuthor Author) const
{
	switch (Author)
	{
	case EForensicMarginaliaAuthor::Kaelen:
		return FLinearColor(0.12f, 0.12f, 0.14f); // Black Iron Carbon Ink
	case EForensicMarginaliaAuthor::Garrett:
		return FLinearColor(0.18f, 0.45f, 0.22f); // Verdant Gall Ink
	case EForensicMarginaliaAuthor::Serafina:
		return FLinearColor(0.85f, 0.65f, 0.15f); // Golden Radiant White Flame Ink
	case EForensicMarginaliaAuthor::SystemCanon:
	default:
		return FLinearColor(0.88f, 0.85f, 0.78f); // Illuminated Parchment Cream
	}
}

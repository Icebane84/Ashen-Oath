// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenMapViewModel.h"

void UAshenMapViewModel::EvaluateSoulState(const FSoulStateVector& StateVector, EAshenWorldviewFilter ActiveFilter)
{
	CachedRenderData.ParchmentSootAlpha = FMath::Clamp(StateVector.Corruption * 0.8f, 0.0f, 1.0f);
	CachedRenderData.InkBleedIntensity = FMath::Clamp(StateVector.Corruption * 1.2f, 0.0f, 1.0f);
	CachedRenderData.VignetteDesaturation = FMath::Clamp((1.0f - StateVector.Resolve) * 0.7f, 0.0f, 1.0f);
	CachedRenderData.bTriggerShadowMarginalia = (StateVector.Corruption >= 0.70f);
	CachedRenderData.bNavigationalSanctityMaintained = true;

	CachedRenderData.FormattedMarginaliaEntries.Empty();
	switch (ActiveFilter)
	{
	case EAshenWorldviewFilter::Garrett:
		CachedRenderData.ActiveLocationHeader = FText::FromString(TEXT("Tactical Assessment — Garrett's Eye"));
		CachedRenderData.FormattedMarginaliaEntries.Add(FText::FromString(TEXT("Garrett: 'Watch the timber supports on the bridge.'")));
		break;
	case EAshenWorldviewFilter::Serafina:
		CachedRenderData.ActiveLocationHeader = FText::FromString(TEXT("Resonance Assessment — Serafina's Eye"));
		CachedRenderData.FormattedMarginaliaEntries.Add(FText::FromString(TEXT("Serafina: 'The Heartstone beneath the riverbed is weeping.'")));
		break;
	case EAshenWorldviewFilter::Kaelen:
	default:
		CachedRenderData.ActiveLocationHeader = FText::FromString(TEXT("Expedition Log — Kaelen's Eye"));
		CachedRenderData.FormattedMarginaliaEntries.Add(FText::FromString(TEXT("Kaelen: 'We crossed before sunrise. Frost thick on iron.'")));
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenMapViewModel: Evaluated Map Render Data (Soot: %.2f, Bleed: %.2f, ShadowMarginalia: %s)"),
		CachedRenderData.ParchmentSootAlpha, CachedRenderData.InkBleedIntensity, CachedRenderData.bTriggerShadowMarginalia ? TEXT("TRUE") : TEXT("FALSE"));
}

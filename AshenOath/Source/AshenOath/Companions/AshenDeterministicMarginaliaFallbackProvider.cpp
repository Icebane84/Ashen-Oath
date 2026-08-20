// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenDeterministicMarginaliaFallbackProvider.h"

UAshenDeterministicMarginaliaFallbackProvider::UAshenDeterministicMarginaliaFallbackProvider()
{
}

TArray<FMarginaliaEntry> UAshenDeterministicMarginaliaFallbackProvider::GenerateDeterministicEntries(
	const FCanonicalSoulStateVector& SoulState,
	const FString& TargetMemoryId) const
{
	TArray<FMarginaliaEntry> Entries;

	// Garrett Annotation
	FMarginaliaEntry GarrettEntry;
	GarrettEntry.EntryId = FGuid::NewGuid().ToString();
	GarrettEntry.Author = EMarginaliaAuthor::Garrett;
	GarrettEntry.TargetMemoryId = TargetMemoryId;
	GarrettEntry.AnchorSlot = EMarginAnchorSlot::RightMargin_Lower;
	GarrettEntry.VisualParams.InkColor = FLinearColor(0.15f, 0.12f, 0.12f, 1.0f); // Charcoal black

	if (SoulState.AccumulatedDysregulation >= 0.70f)
	{
		GarrettEntry.InscriptionText = TEXT("Rationing bolts. If the anchor snaps, I won't hesitate.");
		GarrettEntry.VisualParams.InkDensity = 1.0f;
		GarrettEntry.VisualParams.JitterIntensity = 0.08f;
	}
	else
	{
		GarrettEntry.InscriptionText = TEXT("Flank corridor cleared. Keep your guard up on the ascent.");
		GarrettEntry.VisualParams.InkDensity = 0.85f;
		GarrettEntry.VisualParams.JitterIntensity = 0.02f;
	}
	Entries.Add(GarrettEntry);

	// Serafina Annotation
	FMarginaliaEntry SerafinaEntry;
	SerafinaEntry.EntryId = FGuid::NewGuid().ToString();
	SerafinaEntry.Author = EMarginaliaAuthor::Serafina;
	SerafinaEntry.TargetMemoryId = TargetMemoryId;
	SerafinaEntry.AnchorSlot = EMarginAnchorSlot::LeftMargin_Upper;
	SerafinaEntry.VisualParams.InkColor = FLinearColor(0.35f, 0.25f, 0.20f, 1.0f); // Flowing brown ink

	if (SoulState.DominantLens == EOntologicalLens::Grace)
	{
		SerafinaEntry.InscriptionText = TEXT("The light held. He remembered who he was before the ash.");
		SerafinaEntry.VisualParams.InkDensity = 0.70f;
		SerafinaEntry.VisualParams.JitterIntensity = 0.01f;
	}
	else
	{
		SerafinaEntry.InscriptionText = TEXT("The embers are cold, but the roots still breathe.");
		SerafinaEntry.VisualParams.InkDensity = 0.60f;
		SerafinaEntry.VisualParams.JitterIntensity = 0.01f;
	}
	Entries.Add(SerafinaEntry);

	return Entries;
}

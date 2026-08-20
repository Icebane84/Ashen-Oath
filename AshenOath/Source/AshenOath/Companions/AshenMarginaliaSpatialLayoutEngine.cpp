// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenMarginaliaSpatialLayoutEngine.h"

UAshenMarginaliaSpatialLayoutEngine::UAshenMarginaliaSpatialLayoutEngine()
{
	MarginSlotMaxChars = 90;
	FooterSlotMaxChars = 140;
}

FString UAshenMarginaliaSpatialLayoutEngine::ClampTextToSlotBudget(
	const FString& InText,
	EMarginAnchorSlot Slot) const
{
	const int32 MaxAllowed = (Slot == EMarginAnchorSlot::FooterAnchor) ? FooterSlotMaxChars : MarginSlotMaxChars;

	if (InText.Len() <= MaxAllowed)
	{
		return InText;
	}

	return InText.Left(MaxAllowed - 3) + TEXT("...");
}

TArray<FMarginaliaEntry> UAshenMarginaliaSpatialLayoutEngine::ResolveSpatialCollisions(
	const TArray<FMarginaliaEntry>& InEntries) const
{
	TArray<FMarginaliaEntry> ResolvedEntries;
	TSet<EMarginAnchorSlot> OccupiedSlots;

	for (const FMarginaliaEntry& Entry : InEntries)
	{
		FMarginaliaEntry ClampedEntry = Entry;
		ClampedEntry.InscriptionText = ClampTextToSlotBudget(Entry.InscriptionText, Entry.AnchorSlot);

		// If preferred slot is occupied, find first free margin slot
		if (OccupiedSlots.Contains(ClampedEntry.AnchorSlot))
		{
			if (!OccupiedSlots.Contains(EMarginAnchorSlot::LeftMargin_Upper))
			{
				ClampedEntry.AnchorSlot = EMarginAnchorSlot::LeftMargin_Upper;
			}
			else if (!OccupiedSlots.Contains(EMarginAnchorSlot::RightMargin_Upper))
			{
				ClampedEntry.AnchorSlot = EMarginAnchorSlot::RightMargin_Upper;
			}
			else if (!OccupiedSlots.Contains(EMarginAnchorSlot::LeftMargin_Lower))
			{
				ClampedEntry.AnchorSlot = EMarginAnchorSlot::LeftMargin_Lower;
			}
			else if (!OccupiedSlots.Contains(EMarginAnchorSlot::RightMargin_Lower))
			{
				ClampedEntry.AnchorSlot = EMarginAnchorSlot::RightMargin_Lower;
			}
			else if (!OccupiedSlots.Contains(EMarginAnchorSlot::FooterAnchor))
			{
				ClampedEntry.AnchorSlot = EMarginAnchorSlot::FooterAnchor;
			}
		}

		OccupiedSlots.Add(ClampedEntry.AnchorSlot);
		ResolvedEntries.Add(ClampedEntry);
	}

	return ResolvedEntries;
}

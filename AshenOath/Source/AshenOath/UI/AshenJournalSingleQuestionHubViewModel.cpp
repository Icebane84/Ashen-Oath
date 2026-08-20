// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenJournalSingleQuestionHubViewModel.h"

void UAshenJournalSingleQuestionHubViewModel::TranslateStateVectorToQualitativeSummary(const FSoulStateVector& StateVector)
{
	// Mind State
	if (StateVector.Corruption >= 0.7f)
	{
		CachedSummary.MindStateDescription = FText::FromString(TEXT("Fracturing (High Static Noise)"));
	}
	else if (StateVector.Corruption >= 0.3f)
	{
		CachedSummary.MindStateDescription = FText::FromString(TEXT("Unsettled (Whispers at Periphery)"));
	}
	else
	{
		CachedSummary.MindStateDescription = FText::FromString(TEXT("Lucid (Clear Vision)"));
	}

	// Character Stance
	if (StateVector.Resolve >= 0.8f)
	{
		CachedSummary.CharacterStanceDescription = FText::FromString(TEXT("Unshakeable / Resolute"));
	}
	else
	{
		CachedSummary.CharacterStanceDescription = FText::FromString(TEXT("Hesitant / Wavering"));
	}

	// Relational Anchor
	if (StateVector.Isolation <= 0.2f)
	{
		CachedSummary.RelationalAnchorDescription = FText::FromString(TEXT("Fully Connected"));
	}
	else
	{
		CachedSummary.RelationalAnchorDescription = FText::FromString(TEXT("Distant / Isolated"));
	}

	// Tactical Synergy
	const float AverageTrust = (StateVector.GarrettTrust + StateVector.SerafinaTrust) * 0.5f;
	if (AverageTrust >= 0.8f)
	{
		CachedSummary.TacticalSynergyDescription = FText::FromString(TEXT("Synchronized / In Lockstep"));
	}
	else
	{
		CachedSummary.TacticalSynergyDescription = FText::FromString(TEXT("Friction / Misaligned"));
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenJournalSingleQuestionHubViewModel: MindState='%s', Stance='%s'"),
		*CachedSummary.MindStateDescription.ToString(), *CachedSummary.CharacterStanceDescription.ToString());
}

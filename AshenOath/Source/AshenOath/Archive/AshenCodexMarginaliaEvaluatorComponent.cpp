// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Archive/AshenCodexMarginaliaEvaluatorComponent.h"

UAshenCodexMarginaliaEvaluatorComponent::UAshenCodexMarginaliaEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCodexMarginaliaEvaluatorComponent::EvaluateMarginaliaText(
	const FName& EntryId,
	const FName& CompanionId,
	float FellowshipTrust) const
{
	FString Note;
	if (CompanionId == FName(TEXT("Garrett")))
	{
		Note = (FellowshipTrust >= 0.60f)
			? TEXT("[Garrett's Margin Note]: 'The tension wires in their joints are vulnerable to flanking strikes. Remember this.'")
			: TEXT("[Garrett's Margin Note]: '...Seen too many good soldiers fall to this thing.'");
	}
	else if (CompanionId == FName(TEXT("Serafina")))
	{
		Note = (FellowshipTrust >= 0.60f)
			? TEXT("[Serafina's Margin Note]: 'The White Flame sanctified this relic long before the Fall. Its resonance still echoes.'")
			: TEXT("[Serafina's Margin Note]: 'A sacred text desecrated by the ash.'");
	}
	else
	{
		Note = TEXT("[Marginalia]: 'Faded ink in the margins.'");
	}

	return FText::FromString(Note);
}

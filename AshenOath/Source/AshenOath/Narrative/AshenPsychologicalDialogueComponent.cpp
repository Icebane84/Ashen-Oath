// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenPsychologicalDialogueComponent.h"

UAshenPsychologicalDialogueComponent::UAshenPsychologicalDialogueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentTone = EPsychologicalTone::Resolute;
}
void UAshenPsychologicalDialogueComponent::BeginPlay() { Super::BeginPlay(); }

EPsychologicalTone UAshenPsychologicalDialogueComponent::EvaluateDialogueTone(float Resolve, float Corruption, float Isolation)
{
	if (Corruption >= 0.70f)
	{
		CurrentTone = EPsychologicalTone::Despairing;
	}
	else if (Isolation >= 0.65f)
	{
		CurrentTone = EPsychologicalTone::Cynical;
	}
	else if (Resolve >= 0.80f && Corruption < 0.20f)
	{
		CurrentTone = EPsychologicalTone::Enlightened;
	}
	else
	{
		CurrentTone = EPsychologicalTone::Resolute;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenPsychologicalDialogueComponent: Evaluated Tone -> %d (Resolve: %.2f, Corruption: %.2f, Isolation: %.2f)"),
		static_cast<int32>(CurrentTone), Resolve, Corruption, Isolation);

	return CurrentTone;
}

bool UAshenPsychologicalDialogueComponent::CanSelectDialogueChoice(EPsychologicalTone RequiredTone, float CurrentSanity, float MinSanityRequired) const
{
	if (CurrentSanity < MinSanityRequired) return false;
	if (CurrentTone == EPsychologicalTone::Enlightened) return true; // Enlightened bypasses tone restriction
	return (CurrentTone == RequiredTone);
}

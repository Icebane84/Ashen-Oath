// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenEpistemicGroundingSubsystem.h"

void UAshenEpistemicGroundingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CanonicalEventLog.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenEpistemicGroundingSubsystem: Epistemic Grounding Subsystem initialized."));
}
void UAshenEpistemicGroundingSubsystem::Deinitialize() { Super::Deinitialize(); }

FGuid UAshenEpistemicGroundingSubsystem::RecordCanonicalCombatEvent(FName EncounterID, FName FinisherUsed, EConsequenceProfileTier Tier, bool bIsSynarchy, float Trust)
{
	FCanonicalCombatEvent NewEvent;
	NewEvent.EventID = FGuid::NewGuid();
	NewEvent.EncounterID = EncounterID;
	NewEvent.FinisherUsed = FinisherUsed;
	NewEvent.ProfileTier = Tier;
	NewEvent.bWasTripartiteSynarchy = bIsSynarchy;
	NewEvent.RecordedMutualTrust = Trust;

	CanonicalEventLog.Add(NewEvent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEpistemicGroundingSubsystem: Recorded Layer 0 Canonical Event -> %s (Tier: %d, Synarchy: %s, Trust: %.2f)"),
		*EncounterID.ToString(), static_cast<int32>(Tier), bIsSynarchy ? TEXT("TRUE") : TEXT("FALSE"), Trust);

	return NewEvent.EventID;
}

int32 UAshenEpistemicGroundingSubsystem::GetMilestoneEventsCount() const
{
	int32 Count = 0;
	for (const FCanonicalCombatEvent& Event : CanonicalEventLog)
	{
		if (Event.ProfileTier == EConsequenceProfileTier::Milestone)
		{
			Count++;
		}
	}
	return Count;
}

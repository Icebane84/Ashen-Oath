// Copyright Phoenix Protocol. All rights reserved.

#include "UAICognitiveComponent.h"
#include "Engine/World.h"

UAICognitiveComponent::UAICognitiveComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	RecentActionJournal.Reserve(MaxHistorySize);
}

void UAICognitiveComponent::RecordAction(const FGameplayTag& ActionTag)
{
	const float CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;

	// Shift-on-full is fine at MaxHistorySize == 8 (effectively free). If this
	// grows meaningfully, switch to a head-index circular buffer instead of
	// carrying an O(n) shift cost forward.
	if (RecentActionJournal.Num() >= MaxHistorySize)
	{
		RecentActionJournal.RemoveAt(0);
	}

	FAshenActionHistoryEntry NewEntry;
	NewEntry.ActionTag = ActionTag;
	NewEntry.Timestamp = CurrentTime;
	RecentActionJournal.Add(NewEntry);
}

int32 UAICognitiveComponent::GetRecentExecutionCount(const FGameplayTag& Tag, float WindowSeconds) const
{
	const float CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	int32 ExecutionCount = 0;

	for (const FAshenActionHistoryEntry& Entry : RecentActionJournal)
	{
		if (Entry.ActionTag == Tag && (CurrentTime - Entry.Timestamp) <= WindowSeconds)
		{
			++ExecutionCount;
		}
	}
	return ExecutionCount;
}

void UAICognitiveComponent::SetAbilityCompleted(const FGameplayAbilitySpecHandle& Handle)
{
	CompletedAbilities.Add(Handle);
}

bool UAICognitiveComponent::IsAbilityCompleted(const FGameplayAbilitySpecHandle& Handle) const
{
	return CompletedAbilities.Contains(Handle);
}

void UAICognitiveComponent::ClearAbilityCompletion(const FGameplayAbilitySpecHandle& Handle)
{
	CompletedAbilities.Remove(Handle);
}

void UAICognitiveComponent::UpdateThreatTable(const TArray<FAshenThreatEntry>& NewThreatEntries)
{
	ThreatTable = NewThreatEntries;

	// Fixed: predicate lambda was missing its [] capture list (compile error,
	// even though it captures nothing — the brackets are still required).
	ThreatTable.Sort([](const FAshenThreatEntry& A, const FAshenThreatEntry& B)
	{
		return A.ThreatScore > B.ThreatScore;
	});
}

APawn* UAICognitiveComponent::GetPrimaryThreatTarget() const
{
	for (const FAshenThreatEntry& Entry : ThreatTable)
	{
		if (Entry.ThreatTarget.IsValid())
		{
			return Entry.ThreatTarget.Get();
		}
	}
	return nullptr;
}

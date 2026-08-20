// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCanonicalPromiseSubsystem.h"
#include "Narrative/AshenPromiseLedgerComponent.h"
#include "Narrative/AshenSemanticContextMatcherComponent.h"
#include "Narrative/AshenRetroactiveMarginaliaInscriberComponent.h"

UAshenCanonicalPromiseSubsystem::UAshenCanonicalPromiseSubsystem()
{
}

void UAshenCanonicalPromiseSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	PromiseLedger = NewObject<UAshenPromiseLedgerComponent>(this);
	ContextMatcher = NewObject<UAshenSemanticContextMatcherComponent>(this);
	MarginaliaInscriber = NewObject<UAshenRetroactiveMarginaliaInscriberComponent>(this);
}

void UAshenCanonicalPromiseSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FCanonicalPromiseRecord UAshenCanonicalPromiseSubsystem::SwearCanonicalPromise(
	FName TargetCompanion,
	const FString& PromiseText,
	EPromiseDomainScope Scope,
	FGameplayTag ContextTag)
{
	FCanonicalPromiseRecord Record;

	if (PromiseLedger)
	{
		Record = PromiseLedger->RegisterPromise(TargetCompanion, PromiseText, Scope, ContextTag);
		OnPromiseRegistered.Broadcast(Record);
	}

	return Record;
}

bool UAshenCanonicalPromiseSubsystem::CheckCrisisPromiseReactivation(
	FGameplayTag CurrentCrisisTag,
	FName ActiveCompanion,
	FCanonicalPromiseRecord& OutReactivatedPromise)
{
	if (!PromiseLedger || !ContextMatcher)
	{
		return false;
	}

	TArray<FCanonicalPromiseRecord> ActivePromises = PromiseLedger->GetActivePromises();
	for (const FCanonicalPromiseRecord& Promise : ActivePromises)
	{
		if (ContextMatcher->MatchesCrisisContext(Promise, CurrentCrisisTag, ActiveCompanion))
		{
			OutReactivatedPromise = Promise;
			OnPromiseCrisisReactivated.Broadcast(Promise);
			return true;
		}
	}

	return false;
}

bool UAshenCanonicalPromiseSubsystem::ResolvePromise(const FString& PromiseId, EPromiseResolutionStatus NewStatus)
{
	if (PromiseLedger && PromiseLedger->UpdatePromiseStatus(PromiseId, NewStatus))
	{
		OnPromiseStatusChanged.Broadcast(PromiseId, NewStatus);
		return true;
	}
	return false;
}

FRetroactiveMarginaliaEntry UAshenCanonicalPromiseSubsystem::InscribeRetroactiveMarginalia(
	int32 PageIndex,
	FName Author,
	const FString& NoteContent,
	EMarginaliaInkMedium Medium)
{
	FRetroactiveMarginaliaEntry Entry;

	if (MarginaliaInscriber)
	{
		Entry = MarginaliaInscriber->InscribeMarginalia(PageIndex, Author, NoteContent, Medium);
		OnRetroactiveMarginaliaInscribed.Broadcast(Entry);
	}

	return Entry;
}

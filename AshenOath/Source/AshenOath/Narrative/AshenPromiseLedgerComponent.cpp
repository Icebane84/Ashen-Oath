// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenPromiseLedgerComponent.h"

UAshenPromiseLedgerComponent::UAshenPromiseLedgerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FCanonicalPromiseRecord UAshenPromiseLedgerComponent::RegisterPromise(
	FName TargetCompanion,
	const FString& PromiseText,
	EPromiseDomainScope Scope,
	FGameplayTag ContextTag)
{
	FCanonicalPromiseRecord Record;
	Record.PromiseId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Record.TargetCompanionName = TargetCompanion;
	Record.PromiseText = PromiseText;
	Record.Status = EPromiseResolutionStatus::Active;
	Record.Scope = Scope;
	Record.TriggerContextTag = ContextTag;
	Record.SwornGameTime = FPlatformTime::Seconds();

	PromiseStore.Add(Record);
	return Record;
}

bool UAshenPromiseLedgerComponent::UpdatePromiseStatus(const FString& PromiseId, EPromiseResolutionStatus NewStatus)
{
	for (FCanonicalPromiseRecord& Record : PromiseStore)
	{
		if (Record.PromiseId == PromiseId)
		{
			Record.Status = NewStatus;
			return true;
		}
	}
	return false;
}

TArray<FCanonicalPromiseRecord> UAshenPromiseLedgerComponent::GetActivePromises() const
{
	TArray<FCanonicalPromiseRecord> Active;
	for (const FCanonicalPromiseRecord& Record : PromiseStore)
	{
		if (Record.Status == EPromiseResolutionStatus::Active)
		{
			Active.Add(Record);
		}
	}
	return Active;
}

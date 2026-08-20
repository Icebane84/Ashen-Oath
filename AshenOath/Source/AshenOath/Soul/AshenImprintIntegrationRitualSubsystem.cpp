// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenImprintIntegrationRitualSubsystem.h"

void UAshenImprintIntegrationRitualSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenImprintIntegrationRitualSubsystem: Ritual Subsystem initialized."));
}

void UAshenImprintIntegrationRitualSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenImprintIntegrationRitualSubsystem::PurifyOldestImprint()
{
	if (ActiveImprintCount > 0)
	{
		ActiveImprintCount--;
		if (OnImprintPurified.IsBound())
		{
			OnImprintPurified.Broadcast(ActiveImprintCount);
		}
		UE_LOG(LogTemp, Log, TEXT("UAshenImprintIntegrationRitualSubsystem: Imprint purified cleanly! Remaining: %d"), ActiveImprintCount);
		return true;
	}
	return false;
}

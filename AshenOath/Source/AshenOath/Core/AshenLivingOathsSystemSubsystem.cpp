// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 313: Ashen Living Oaths System Subsystem

#include "AshenLivingOathsSystemSubsystem.h"

void UAshenLivingOathsSystemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveBoundOaths.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathsSystemSubsystem: Initialized — Living Oaths Ledger ONLINE."));
}

bool UAshenLivingOathsSystemSubsystem::BindLivingOath(FName OathPactID)
{
	if (OathPactID.IsNone()) return false;

	ActiveBoundOaths.Add(OathPactID);
	OnLivingOathStateChanged.Broadcast(OathPactID, true);

	UE_LOG(LogTemp, Warning, TEXT("UAshenLivingOathsSystemSubsystem: LIVING OATH BOUND — '%s' (Party Combat Buff Granted)."),
		*OathPactID.ToString());

	return true;
}

void UAshenLivingOathsSystemSubsystem::BreakLivingOath(FName OathPactID)
{
	if (ActiveBoundOaths.Contains(OathPactID))
	{
		ActiveBoundOaths.Remove(OathPactID);
		OnLivingOathStateChanged.Broadcast(OathPactID, false);

		UE_LOG(LogTemp, Warning, TEXT("UAshenLivingOathsSystemSubsystem: LIVING OATH BROKEN — '%s' (Party Buff Forfeited)."),
			*OathPactID.ToString());
	}
}

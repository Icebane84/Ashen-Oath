// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenLivingOathRegistrySubsystem.h"

void UAshenLivingOathRegistrySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathRegistrySubsystem: Living Oath Registry Subsystem initialized."));
}

void UAshenLivingOathRegistrySubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenLivingOathRegistrySubsystem::SwearOath(FName OathID, FText Description)
{
	FOathRecord NewOath;
	NewOath.OathID = OathID;
	NewOath.OathDescription = Description;
	NewOath.bFulfilled = false;
	NewOath.bBroken = false;
	ActiveOathRegistry.Add(NewOath);

	ActiveOathBurden += 0.25f;
	if (OnLivingOathSworn.IsBound()) OnLivingOathSworn.Broadcast(NewOath);

	UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathRegistrySubsystem: Sworn oath '%s' (Total Burden: %.2f)"), *OathID.ToString(), ActiveOathBurden);
	return true;
}

bool UAshenLivingOathRegistrySubsystem::FulfillOath(FName OathID)
{
	for (FOathRecord& Oath : ActiveOathRegistry)
	{
		if (Oath.OathID == OathID && !Oath.bFulfilled && !Oath.bBroken)
		{
			Oath.bFulfilled = true;
			ActiveOathBurden = FMath::Max(0.0f, ActiveOathBurden - 0.35f);
			if (OnLivingOathFulfilled.IsBound()) OnLivingOathFulfilled.Broadcast(Oath);
			UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathRegistrySubsystem: FULFILLED oath '%s' (Total Burden: %.2f)"), *OathID.ToString(), ActiveOathBurden);
			return true;
		}
	}
	return false;
}

bool UAshenLivingOathRegistrySubsystem::BreachOath(FName OathID)
{
	for (FOathRecord& Oath : ActiveOathRegistry)
	{
		if (Oath.OathID == OathID && !Oath.bFulfilled && !Oath.bBroken)
		{
			Oath.bBroken = true;
			ActiveOathBurden += 0.50f; // Breach heavy burden penalty
			if (OnLivingOathBreached.IsBound()) OnLivingOathBreached.Broadcast(Oath);
			UE_LOG(LogTemp, Error, TEXT("UAshenLivingOathRegistrySubsystem: BREACHED oath '%s'! Burden spiked to %.2f"), *OathID.ToString(), ActiveOathBurden);
			return true;
		}
	}
	return false;
}

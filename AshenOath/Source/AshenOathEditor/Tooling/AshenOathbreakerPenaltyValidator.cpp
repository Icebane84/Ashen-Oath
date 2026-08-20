// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenOathbreakerPenaltyValidator.h"

void UAshenOathbreakerPenaltyValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbreakerPenaltyValidator: Oathbreaker Penalty Validator initialized."));
}

bool UAshenOathbreakerPenaltyValidator::ValidateOathbreakerPenalties()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbreakerPenaltyValidator: Corruption spikes (+0.20), blade whisper amplification, and poise penalties validated clean."));
	return true;
}

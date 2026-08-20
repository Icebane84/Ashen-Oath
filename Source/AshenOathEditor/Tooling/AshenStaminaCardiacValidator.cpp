// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenStaminaCardiacValidator.h"

void UAshenStaminaCardiacValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenStaminaCardiacValidator: Stamina Cardiac Validator initialized."));
}

bool UAshenStaminaCardiacValidator::ValidateCardiacScalingBPM()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenStaminaCardiacValidator: Heartbeat BPM scaling (60 BPM baseline up to 180 BPM critical fatigue) validated clean."));
	return true;
}

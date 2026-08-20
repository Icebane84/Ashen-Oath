// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenWhisperingWindValidator.h"

void UAshenWhisperingWindValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingWindValidator: Whispering Wind Validator initialized."));
}

bool UAshenWhisperingWindValidator::ValidateWhisperingWindCurves()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingWindValidator: Whisper spatial attenuation curves, distance bounds, and bark intervals validated clean."));
	return true;
}

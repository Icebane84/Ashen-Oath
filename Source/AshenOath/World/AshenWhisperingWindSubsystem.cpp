// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenWhisperingWindSubsystem.h"

void UAshenWhisperingWindSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentWhisperIntensity = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingWindSubsystem: Whispering Wind Subsystem initialized."));
}
void UAshenWhisperingWindSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenWhisperingWindSubsystem::UpdateWhisperIntensity(float Isolation, float IntegrationDebt)
{
	CurrentWhisperIntensity = FMath::Clamp((Isolation * 0.5f) + (IntegrationDebt * 0.5f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingWindSubsystem: Whisper Intensity updated to %.2f (Isolation: %.2f, Debt: %.2f)"),
		CurrentWhisperIntensity, Isolation, IntegrationDebt);
}

void UAshenWhisperingWindSubsystem::TriggerSpatializedBark(FVector Location, FName BarkID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingWindSubsystem: Triggered spatial bark '%s' at %s (Intensity: %.2f)."),
		*BarkID.ToString(), *Location.ToString(), CurrentWhisperIntensity);
}

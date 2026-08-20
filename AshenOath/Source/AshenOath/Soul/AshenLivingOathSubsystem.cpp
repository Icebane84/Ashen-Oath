// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenLivingOathSubsystem.h"

void UAshenLivingOathSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveOath = EAshenLivingOathType::None;
	OathState = EAshenOathState::Unsworn;
	OathFulfillmentPercent = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathSubsystem: Living Oath Subsystem initialized."));
}

bool UAshenLivingOathSubsystem::SwearLivingOath(EAshenLivingOathType NewOath)
{
	ActiveOath = NewOath;
	OathState = EAshenOathState::Active;
	OathFulfillmentPercent = 0.0f;

	if (OnLivingOathStateChanged.IsBound())
	{
		OnLivingOathStateChanged.Broadcast(ActiveOath, OathState);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenLivingOathSubsystem: Kaelen has sworn a Living Oath (Type: %d)!"), (int32)ActiveOath);
	return true;
}

void UAshenLivingOathSubsystem::ProgressOathFulfillment(float DeltaPercent)
{
	if (OathState != EAshenOathState::Active) return;

	OathFulfillmentPercent = FMath::Clamp(OathFulfillmentPercent + DeltaPercent, 0.0f, 1.0f);
	if (OathFulfillmentPercent >= 1.0f)
	{
		OathState = EAshenOathState::Fulfilled;
		if (OnLivingOathStateChanged.IsBound())
		{
			OnLivingOathStateChanged.Broadcast(ActiveOath, OathState);
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenLivingOathSubsystem: Living Oath (Type: %d) FULFILLED!"), (int32)ActiveOath);
	}
}

void UAshenLivingOathSubsystem::FractureLivingOath()
{
	if (OathState != EAshenOathState::Active) return;

	OathState = EAshenOathState::Fractured;
	if (OnLivingOathStateChanged.IsBound())
	{
		OnLivingOathStateChanged.Broadcast(ActiveOath, OathState);
	}
	UE_LOG(LogTemp, Error, TEXT("UAshenLivingOathSubsystem: LIVING OATH FRACTURED! Oathbreaker penalties initiated."));
}

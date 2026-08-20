// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_PoiseComponent.h"

UAshenOath_PoiseComponent::UAshenOath_PoiseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MaxPoise = 100.0f;
	CurrentPoise = 0.0f;
	bIsHyperArmorActive = false;
}

void UAshenOath_PoiseComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentPoise = MaxPoise;
}

void UAshenOath_PoiseComponent::ApplyPoiseDamage(float Amount)
{
	if (bIsHyperArmorActive)
	{
		return;
	}

	CurrentPoise = FMath::Clamp(CurrentPoise - Amount, 0.0f, MaxPoise);

	if (CurrentPoise <= 0.0f)
	{
		OnPostureBroken.Broadcast();
	}
}

void UAshenOath_PoiseComponent::ResetPoise()
{
	CurrentPoise = MaxPoise;
}

void UAshenOath_PoiseComponent::SetCurrentPoise(float NewPoise)
{
	if (bIsHyperArmorActive)
	{
		return;
	}

	CurrentPoise = FMath::Clamp(NewPoise, 0.0f, MaxPoise);

	if (CurrentPoise <= 0.0f)
	{
		OnPostureBroken.Broadcast();
	}
}

void UAshenOath_PoiseComponent::SetMaxPoise(float NewMaxPoise)
{
	MaxPoise = FMath::Max(1.0f, NewMaxPoise);
	CurrentPoise = FMath::Clamp(CurrentPoise, 0.0f, MaxPoise);
}

void UAshenOath_PoiseComponent::SetHyperArmorActive(bool bActive)
{
	bIsHyperArmorActive = bActive;
}

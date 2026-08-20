// AshenOath_CurrencyComponent.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenOath_CurrencyComponent.h"

DEFINE_LOG_CATEGORY(LogAshenCurrency);

UAshenOath_CurrencyComponent::UAshenOath_CurrencyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	Embers = 0.0f;
	Ash = 0.0f;
}

void UAshenOath_CurrencyComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOath_CurrencyComponent::AddEmbers(float Amount)
{
	if (Amount <= 0.0f) return;

	Embers += Amount;
	UE_LOG(LogAshenCurrency, Log, TEXT("AddEmbers: +%.1f (Total Embers: %.1f)"), Amount, Embers);
	OnCurrencyChanged.Broadcast(Embers, Ash);
}

bool UAshenOath_CurrencyComponent::DeductEmbers(float Amount)
{
	if (Amount <= 0.0f || Embers < Amount)
	{
		return false;
	}

	Embers -= Amount;
	UE_LOG(LogAshenCurrency, Log, TEXT("DeductEmbers: -%.1f (Remaining Embers: %.1f)"), Amount, Embers);
	OnCurrencyChanged.Broadcast(Embers, Ash);
	return true;
}

float UAshenOath_CurrencyComponent::DropEmbersOnDeath()
{
	const float LostEmbers = Embers;
	Embers = 0.0f;
	UE_LOG(LogAshenCurrency, Warning, TEXT("DropEmbersOnDeath: Lost %.1f Embers on death!"), LostEmbers);
	OnCurrencyChanged.Broadcast(Embers, Ash);
	return LostEmbers;
}

void UAshenOath_CurrencyComponent::AddAsh(float Amount)
{
	if (Amount <= 0.0f) return;

	Ash += Amount;
	UE_LOG(LogAshenCurrency, Log, TEXT("AddAsh: +%.1f (Total Ash: %.1f)"), Amount, Ash);
	OnCurrencyChanged.Broadcast(Embers, Ash);
}

bool UAshenOath_CurrencyComponent::DeductAsh(float Amount)
{
	if (Amount <= 0.0f || Ash < Amount)
	{
		return false;
	}

	Ash -= Amount;
	UE_LOG(LogAshenCurrency, Log, TEXT("DeductAsh: -%.1f (Remaining Ash: %.1f)"), Amount, Ash);
	OnCurrencyChanged.Broadcast(Embers, Ash);
	return true;
}

void UAshenOath_CurrencyComponent::GrantAshOnIntegration(float BaseGrant, float ResolveMultiplier)
{
	const float EarnedAsh = BaseGrant * FMath::Clamp(ResolveMultiplier, 0.1f, 2.0f);
	AddAsh(EarnedAsh);
	UE_LOG(LogAshenCurrency, Log, TEXT("GrantAshOnIntegration: Earned %.1f Ash (Base: %.1f, ResolveMult: %.2f)"),
		EarnedAsh, BaseGrant, ResolveMultiplier);
}

void UAshenOath_CurrencyComponent::LoadCurrencyState(float SavedEmbers, float SavedAsh)
{
	Embers = FMath::Max(0.0f, SavedEmbers);
	Ash = FMath::Max(0.0f, SavedAsh);
	UE_LOG(LogAshenCurrency, Log, TEXT("LoadCurrencyState: Restored Embers: %.1f | Ash: %.1f"), Embers, Ash);
	OnCurrencyChanged.Broadcast(Embers, Ash);
}

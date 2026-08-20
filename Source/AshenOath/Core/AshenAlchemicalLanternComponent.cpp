// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenAlchemicalLanternComponent.h"

UAshenAlchemicalLanternComponent::UAshenAlchemicalLanternComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalLanternComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenAlchemicalLanternComponent::ToggleLantern(bool bLit)
{
	if (bLit && CurrentFuel <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalLanternComponent: Cannot ignite lantern — out of oil fuel!"));
		return;
	}

	bIsLanternLit = bLit;
	if (OnLanternToggled.IsBound())
	{
		OnLanternToggled.Broadcast(bIsLanternLit);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalLanternComponent: Lantern %s (Fuel: %.1f%%)"),
		bIsLanternLit ? TEXT("LIT") : TEXT("EXTINGUISHED"), CurrentFuel);
}

void UAshenAlchemicalLanternComponent::RefuelLantern(float FuelAmount)
{
	RefillFuel(FuelAmount);
}

void UAshenAlchemicalLanternComponent::RefillFuel(float Amount)
{
	CurrentFuel = FMath::Clamp(CurrentFuel + Amount, 0.0f, MaxFuel);
	CalculatedLightRadius = (CurrentFuel / MaxFuel) * 1000.0f;
	if (OnLanternFuelChanged.IsBound())
	{
		OnLanternFuelChanged.Broadcast(CurrentFuel, CalculatedLightRadius);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalLanternComponent: Refueled with %.1f oil. Total: %.1f%%"), Amount, CurrentFuel);
}

void UAshenAlchemicalLanternComponent::ConsumeFuel(float DeltaTime)
{
	if (!bIsLanternLit) return;

	CurrentFuel = FMath::Clamp(CurrentFuel - (BurnRate * DeltaTime), 0.0f, MaxFuel);
	CalculatedLightRadius = (CurrentFuel / MaxFuel) * 1000.0f;
	if (OnLanternFuelChanged.IsBound())
	{
		OnLanternFuelChanged.Broadcast(CurrentFuel, CalculatedLightRadius);
	}

	if (CurrentFuel <= 0.0f)
	{
		ToggleLantern(false);
	}
}

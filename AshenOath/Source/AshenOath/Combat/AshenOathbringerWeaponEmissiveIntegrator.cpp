// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathbringerWeaponEmissiveIntegrator.h"

UAshenOathbringerWeaponEmissiveIntegrator::UAshenOathbringerWeaponEmissiveIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenOathbringerWeaponEmissiveIntegrator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	OathbringerEmissiveScalar = FMath::Clamp(NewState.Corruption * 4.0f, 0.0f, 4.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerWeaponEmissiveIntegrator: Oathbringer sword emissive resonance updated to %.2f"), OathbringerEmissiveScalar);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 486: Ashen Enemy Family Veil Hound Component

#include "AshenEnemyFamilyVeilHoundComponent.h"

UAshenEnemyFamilyVeilHoundComponent::UAshenEnemyFamilyVeilHoundComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsStealthed = false;
	PounceDamageMultiplier = 1.5f;
}

void UAshenEnemyFamilyVeilHoundComponent::SetHoundStealthState(bool bStealthed)
{
	bIsStealthed = bStealthed;
	PounceDamageMultiplier = bStealthed ? 2.0f : 1.0f;

	OnStealthStateChanged.Broadcast(bStealthed, PounceDamageMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEnemyFamilyVeilHoundComponent: VEIL HOUND STEALTH -> %s (Pounce Multiplier: %.1fx)."),
		bStealthed ? TEXT("ACTIVE") : TEXT("REVEALED"), PounceDamageMultiplier);
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 801: Ashen Aegis Half-Sword Brace Component

#include "AshenAegisHalfSwordBraceComponent.h"

UAshenAegisHalfSwordBraceComponent::UAshenAegisHalfSwordBraceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsBracing = false;
}

void UAshenAegisHalfSwordBraceComponent::ExecuteHalfSwordBrace(float IncomingDamage)
{
	bIsBracing = true;
	const float StaminaDrain = IncomingDamage * 0.4f; // 40% of damage absorbed as stamina drain
	const float ChipDamage = IncomingDamage * 0.10f;   // 10% chip damage passes through

	OnHalfSwordBraceExecuted.Broadcast(StaminaDrain, ChipDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAegisHalfSwordBraceComponent: HALF-SWORD BRACE EXECUTED -> Stamina Drained: -%.1f | Chip Damage: %.1f HP."),
		StaminaDrain, ChipDamage);
}

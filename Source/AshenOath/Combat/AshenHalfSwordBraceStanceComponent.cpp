// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 662: Ashen Half-Sword Brace Stance Component

#include "AshenHalfSwordBraceStanceComponent.h"

UAshenHalfSwordBraceStanceComponent::UAshenHalfSwordBraceStanceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsBracingActive = false;
}

void UAshenHalfSwordBraceStanceComponent::AbsorbBehemothImpact(float IncomingDamage)
{
	const float AbsorbedDamage = IncomingDamage * 0.7f; // 70% damage reduction
	const bool bPreventedKnockdown = true;

	OnBraceImpact.Broadcast(AbsorbedDamage, bPreventedKnockdown);

	UE_LOG(LogTemp, Warning, TEXT("UAshenHalfSwordBraceStanceComponent: BEHEMOTH IMPACT ABSORBED -> Incoming: %.1f | Absorbed: %.1f | Knockdown Prevented: TRUE."),
		IncomingDamage, AbsorbedDamage);
}

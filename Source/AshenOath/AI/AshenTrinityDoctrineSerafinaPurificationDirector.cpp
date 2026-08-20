// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 807: Ashen Trinity Doctrine Serafina Purification Director

#include "AshenTrinityDoctrineSerafinaPurificationDirector.h"

float UAshenTrinityDoctrineSerafinaPurificationDirector::EvaluateSerafinaParryPurificationFlow(float SerafinaTrustLevel)
{
	const bool bHighTrust = (SerafinaTrustLevel >= 60.0f);
	const float StaminaRestored = bHighTrust ? 100.0f : 20.0f; // Instant full stamina restore on parry at high trust

	OnPurificationEvaluated.Broadcast(StaminaRestored, bHighTrust);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTrinityDoctrineSerafinaPurificationDirector: SERAFINA PURIFICATION EVALUATED -> Trust: %.1f%% | Instant Stamina Restored: +%.0f | Harmonic Flow: %s."),
		SerafinaTrustLevel, StaminaRestored, bHighTrust ? TEXT("ACTIVE") : TEXT("THROTTLED"));

	return StaminaRestored;
}

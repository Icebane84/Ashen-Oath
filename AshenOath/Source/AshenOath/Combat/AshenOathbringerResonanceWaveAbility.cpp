// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 777: Ashen Oathbringer Resonance Wave Ability

#include "AshenOathbringerResonanceWaveAbility.h"

void UAshenOathbringerResonanceWaveAbility::ExecuteResonanceWave(FVector Direction, float BaseDamage)
{
	OnResonanceWaveExecuted.Broadcast(Direction, BaseDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerResonanceWaveAbility: RESONANCE WAVE EXECUTED -> Direction: (%s) | Resonance Damage: %.1f HP."),
		*Direction.ToString(), BaseDamage);
}

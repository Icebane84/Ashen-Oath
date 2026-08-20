// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 728: Ashen Serafina Sun Pulse Sanctuary Ability

#include "AshenSerafinaSunPulseSanctuaryAbility.h"

void UAshenSerafinaSunPulseSanctuaryAbility::ExecuteSunPulseSanctuary(float BaseWillpowerRestoration)
{
	const float BlindDuration = 4.0f; // 4 second enemy blind
	OnSunPulseExecuted.Broadcast(BaseWillpowerRestoration, BlindDuration);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaSunPulseSanctuaryAbility: SUN PULSE SANCTUARY EXECUTED -> Restored Willpower: +%.1f | Blind Duration: %.1fs."),
		BaseWillpowerRestoration, BlindDuration);
}

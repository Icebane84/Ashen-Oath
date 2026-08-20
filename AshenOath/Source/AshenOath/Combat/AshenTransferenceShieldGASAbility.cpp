// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTransferenceShieldGASAbility.h"

UAshenTransferenceShieldGASAbility::UAshenTransferenceShieldGASAbility()
{
	MaxShieldAbsorption = 400.0f;
	SanityConversionRatio = 0.25f;
}

float UAshenTransferenceShieldGASAbility::AbsorbDamageAndConvert(float IncomingDamage, float& OutSanityRestored)
{
	const float Absorbed = FMath::Min(IncomingDamage, MaxShieldAbsorption);
	const float Unmitigated = IncomingDamage - Absorbed;
	OutSanityRestored = Absorbed * SanityConversionRatio;

	UE_LOG(LogTemp, Log, TEXT("UAshenTransferenceShieldGASAbility: Shield absorbed %.1f damage -> Restored %.1f Companion Sanity (Unmitigated: %.1f)."),
		Absorbed, OutSanityRestored, Unmitigated);

	return Unmitigated;
}

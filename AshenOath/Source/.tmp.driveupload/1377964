// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenInterpretiveLensGASAbility.h"

UAshenInterpretiveLensGASAbility::UAshenInterpretiveLensGASAbility()
{
	LensAuraRadius = 900.0f;
}

bool UAshenInterpretiveLensGASAbility::ActivateLensResonance(AActor* InstigatorActor, EInterpretiveLens Lens)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenInterpretiveLensGASAbility: Activated Lens Resonance Aura (Lens: %d, Radius: %.1f)."),
		static_cast<int32>(Lens), LensAuraRadius);
	return true;
}

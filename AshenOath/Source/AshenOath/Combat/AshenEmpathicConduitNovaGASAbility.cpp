// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenEmpathicConduitNovaGASAbility.h"

UAshenEmpathicConduitNovaGASAbility::UAshenEmpathicConduitNovaGASAbility()
{
	BaseNovaDamage = 1200.0f;
	NovaRadius = 1400.0f;
	MinTrustRequired = 0.70f;
}

bool UAshenEmpathicConduitNovaGASAbility::UnleashEmpathicNova(AActor* InstigatorActor, float CurrentMutualTrust)
{
	if (!InstigatorActor || CurrentMutualTrust < MinTrustRequired) return false;

	UE_LOG(LogTemp, Warning, TEXT("UAshenEmpathicConduitNovaGASAbility: EMPATHIC CONDUIT NOVA UNLEASHED (DMG: %.1f, Radius: %.1fuu, Trust: %.2f)!"),
		BaseNovaDamage, NovaRadius, CurrentMutualTrust);

	return true;
}

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSanctuaryAnchorGASAbility.h"

UAshenSanctuaryAnchorGASAbility::UAshenSanctuaryAnchorGASAbility()
{
	AnchorDurationSeconds = 6.0f;
}

bool UAshenSanctuaryAnchorGASAbility::CreateSanctuaryAnchor(AActor* InstigatorActor, const FVector& AnchorLocation)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryAnchorGASAbility: Serafina Created Sanctuary Anchor at (%s) for %.1fs! Ordered reality established!"),
		*AnchorLocation.ToString(), AnchorDurationSeconds);
	return true;
}

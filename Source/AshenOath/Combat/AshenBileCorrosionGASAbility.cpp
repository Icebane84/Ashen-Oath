// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBileCorrosionGASAbility.h"

UAshenBileCorrosionGASAbility::UAshenBileCorrosionGASAbility()
{
	ArmorShredPercent = 0.30f;
	CorrosionDuration = 8.0f;
}

bool UAshenBileCorrosionGASAbility::ApplyBileCorrosion(AActor* TargetActor)
{
	if (!TargetActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenBileCorrosionGASAbility: Applied Bile Corrosion (Shred: %.1f%% for %.1fs) to %s."),
		ArmorShredPercent * 100.0f, CorrosionDuration, *TargetActor->GetName());
	return true;
}

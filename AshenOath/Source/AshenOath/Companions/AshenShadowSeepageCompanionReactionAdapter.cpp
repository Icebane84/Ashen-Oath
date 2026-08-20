// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenShadowSeepageCompanionReactionAdapter.h"

UAshenShadowSeepageCompanionReactionAdapter::UAshenShadowSeepageCompanionReactionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShadowSeepageCompanionReactionAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenShadowSeepageCompanionReactionAdapter::EvaluateCompanionProximityOffset(EShadowSeepagePhase Phase) const
{
	float Offset = 0.0f;
	if (Phase == EShadowSeepagePhase::CrimsonSurge)
	{
		Offset = 250.0f; // Step back from violent sparks
	}
	else if (Phase == EShadowSeepagePhase::BileSeepage)
	{
		Offset = 100.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenShadowSeepageCompanionReactionAdapter: Seepage Phase %d -> Companion Spacing Offset: %.1fuu"),
		static_cast<int32>(Phase), Offset);

	return Offset;
}

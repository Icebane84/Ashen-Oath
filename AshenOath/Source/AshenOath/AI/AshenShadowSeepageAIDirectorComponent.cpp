// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenShadowSeepageAIDirectorComponent.h"

UAshenShadowSeepageAIDirectorComponent::UAshenShadowSeepageAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShadowSeepageAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenShadowSeepageAIDirectorComponent::CalculateEnemyPanicRadius(EShadowSeepagePhase Phase) const
{
	float Radius = 0.0f;
	switch (Phase)
	{
	case EShadowSeepagePhase::CrimsonSurge:
		Radius = 900.0f; // Wide terror zone
		break;
	case EShadowSeepagePhase::BileSeepage:
		Radius = 450.0f;
		break;
	case EShadowSeepagePhase::VeinGlow:
		Radius = 150.0f;
		break;
	case EShadowSeepagePhase::Dormant:
	default:
		Radius = 0.0f;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenShadowSeepageAIDirectorComponent: Seepage Phase %d -> Enemy Panic Radius: %.1fuu"),
		static_cast<int32>(Phase), Radius);

	return Radius;
}

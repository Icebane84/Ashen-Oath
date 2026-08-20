// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "VFX/AshenKaelenShadowMarkVFXComponent.h"

UAshenKaelenShadowMarkVFXComponent::UAshenKaelenShadowMarkVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ForearmSocketName = FName(TEXT("SOCKET_ShadowMark_LeftForearm"));
	CurrentPhase = EShadowSeepagePhase::Dormant;
}
void UAshenKaelenShadowMarkVFXComponent::BeginPlay() { Super::BeginPlay(); }

EShadowSeepagePhase UAshenKaelenShadowMarkVFXComponent::EvaluateSeepagePhase(float CorruptionScalar)
{
	const float C = FMath::Clamp(CorruptionScalar, 0.0f, 1.0f);
	if (C >= 0.70f)
	{
		CurrentPhase = EShadowSeepagePhase::CrimsonSurge;
	}
	else if (C >= 0.35f)
	{
		CurrentPhase = EShadowSeepagePhase::BileSeepage;
	}
	else if (C >= 0.10f)
	{
		CurrentPhase = EShadowSeepagePhase::VeinGlow;
	}
	else
	{
		CurrentPhase = EShadowSeepagePhase::Dormant;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenKaelenShadowMarkVFXComponent: Corruption %.2f -> Evaluated Seepage Phase: %d"),
		C, static_cast<int32>(CurrentPhase));

	return CurrentPhase;
}

float UAshenKaelenShadowMarkVFXComponent::CalculateNormalOffset(float CorruptionScalar) const
{
	const float C = FMath::Clamp(CorruptionScalar, 0.0f, 1.0f);
	// Lerp(0.1, 1.5, C) constrained strictly <= 2.0
	const float Offset = FMath::Clamp(FMath::Lerp(0.1f, 1.5f, C), 0.1f, 2.0f);
	return Offset;
}

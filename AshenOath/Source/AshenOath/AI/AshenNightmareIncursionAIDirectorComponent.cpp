// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenNightmareIncursionAIDirectorComponent.h"

UAshenNightmareIncursionAIDirectorComponent::UAshenNightmareIncursionAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxConcurrentPhantoms = 6;
}
void UAshenNightmareIncursionAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

int32 UAshenNightmareIncursionAIDirectorComponent::CalculateDesiredPhantomCount(float IncursionIntensity, int32 ActiveRifts) const
{
	const int32 BaseFromIntensity = FMath::RoundToInt(IncursionIntensity * 4.0f);
	const int32 BaseFromRifts = ActiveRifts * 2;
	const int32 Total = FMath::Clamp(BaseFromIntensity + BaseFromRifts, 0, MaxConcurrentPhantoms);

	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareIncursionAIDirectorComponent: Desired Phantoms: %d (Intensity: %.2f, Rifts: %d)"),
		Total, IncursionIntensity, ActiveRifts);

	return Total;
}

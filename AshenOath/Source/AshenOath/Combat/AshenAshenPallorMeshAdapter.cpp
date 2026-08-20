// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAshenPallorMeshAdapter.h"

UAshenAshenPallorMeshAdapter::UAshenAshenPallorMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	SkinPallorDesaturation = 0.0f;
	CrimsonEyeEmissive = 0.0f;
}
void UAshenAshenPallorMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenAshenPallorMeshAdapter::UpdateUnchainedFacialMorphs(float CorruptionAmount)
{
	const float C = FMath::Clamp(CorruptionAmount, 0.0f, 1.0f);
	if (C >= 0.70f)
	{
		SkinPallorDesaturation = (C - 0.70f) / 0.30f; // 0.0 to 1.0
		CrimsonEyeEmissive = SkinPallorDesaturation * 4.0f; // Up to 4.0 Glow
	}
	else
	{
		SkinPallorDesaturation = 0.0f;
		CrimsonEyeEmissive = 0.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenAshenPallorMeshAdapter: Ashen Pallor: %.2f | Crimson Eye Emissive: %.2f"),
		SkinPallorDesaturation, CrimsonEyeEmissive);
}

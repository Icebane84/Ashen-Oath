// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenWeaponRunecraftMeshAdapter.h"

UAshenWeaponRunecraftMeshAdapter::UAshenWeaponRunecraftMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	SootLayerOpacity = 1.0f;
	GoldRuneEmissiveIntensity = 0.0f;
}
void UAshenWeaponRunecraftMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWeaponRunecraftMeshAdapter::UpdateRunecraftState(int32 TotalSynarchyKills)
{
	// Soot decreases from 1.0 down to 0.0 across 10 kills
	const float CleanProgress = FMath::Clamp(static_cast<float>(TotalSynarchyKills) / 10.0f, 0.0f, 1.0f);
	SootLayerOpacity = 1.0f - CleanProgress;
	GoldRuneEmissiveIntensity = CleanProgress * 2.5f;

	UE_LOG(LogTemp, Log, TEXT("UAshenWeaponRunecraftMeshAdapter: Oathbringer Soot Opacity: %.2f | Gold Rune Emissive: %.2f"),
		SootLayerOpacity, GoldRuneEmissiveIntensity);
}

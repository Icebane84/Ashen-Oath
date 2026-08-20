// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenWeaponRuneEmissivePostProcessAdapter.h"

UAshenWeaponRuneEmissivePostProcessAdapter::UAshenWeaponRuneEmissivePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWeaponRuneEmissivePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWeaponRuneEmissivePostProcessAdapter::ApplyWeaponRuneEmissive(int32 RuneTier, float GlowIntensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWeaponRuneEmissivePostProcessAdapter: Postprocess updated — Rune Tier %d (Glow Intensity: %.2f)"),
		RuneTier, GlowIntensity);
}

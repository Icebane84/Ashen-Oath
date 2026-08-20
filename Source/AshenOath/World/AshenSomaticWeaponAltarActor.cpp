// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSomaticWeaponAltarActor.h"

AAshenSomaticWeaponAltarActor::AAshenSomaticWeaponAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;
	CleanedRuneRatio = 0.0f;
}
void AAshenSomaticWeaponAltarActor::BeginPlay() { Super::BeginPlay(); }

void AAshenSomaticWeaponAltarActor::UpdateWeaponCleansingProgress(int32 SynarchyExecutionsCount)
{
	CleanedRuneRatio = FMath::Clamp(static_cast<float>(SynarchyExecutionsCount) / 10.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("AAshenSomaticWeaponAltarActor: Oathbringer Rune Cleansing: %.1f%% (Executions: %d)"),
		CleanedRuneRatio * 100.0f, SynarchyExecutionsCount);
}

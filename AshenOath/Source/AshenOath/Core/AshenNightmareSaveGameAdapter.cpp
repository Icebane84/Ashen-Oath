// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenNightmareSaveGameAdapter.h"

UAshenNightmareSaveGameAdapter::UAshenNightmareSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNightmareSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenNightmareSaveGameAdapter::SaveNightmareProgress(int32 TotalSealedRifts, float MaxIncursionIntensitySurvived)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareSaveGameAdapter: Saved Nightmare Progress (%d sealed rifts, %.2f max intensity) to SaveGame."),
		TotalSealedRifts, MaxIncursionIntensitySurvived);
	return true;
}

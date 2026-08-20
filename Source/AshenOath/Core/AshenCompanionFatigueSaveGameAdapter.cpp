// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenCompanionFatigueSaveGameAdapter.h"

UAshenCompanionFatigueSaveGameAdapter::UAshenCompanionFatigueSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionFatigueSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenCompanionFatigueSaveGameAdapter::SaveCompanionFatigueStates(float GarrettFatigue, float SerafinaFatigue, float KaelenFatigue)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionFatigueSaveGameAdapter: Saved Companion Fatigue (G: %.2f, S: %.2f, K: %.2f) to SaveGame."),
		GarrettFatigue, SerafinaFatigue, KaelenFatigue);
	return true;
}

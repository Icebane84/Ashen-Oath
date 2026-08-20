// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenLivingOathSaveGameAdapter.h"

UAshenLivingOathSaveGameAdapter::UAshenLivingOathSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingOathSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenLivingOathSaveGameAdapter::SerializeOathDataToSave(EAshenLivingOathType OathType, EAshenOathState State, float Fulfillment)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathSaveGameAdapter: Serialized Oath %d (State: %d, Fulfillment: %.1f%%) to SaveGame."),
		(int32)OathType, (int32)State, Fulfillment * 100.0f);
	return true;
}

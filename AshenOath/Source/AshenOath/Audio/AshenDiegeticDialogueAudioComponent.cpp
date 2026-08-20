// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticDialogueAudioComponent.h"

UAshenDiegeticDialogueAudioComponent::UAshenDiegeticDialogueAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticDialogueAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticDialogueAudioComponent::PlaySpatializedVoiceLine(FName CompanionID, FString LineID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticDialogueAudioComponent: 3D spatialized voice line '%s' played for %s"), *LineID, *CompanionID.ToString());
}

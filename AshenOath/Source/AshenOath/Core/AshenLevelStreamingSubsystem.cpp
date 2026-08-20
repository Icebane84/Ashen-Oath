// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenLevelStreamingSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LatentActionManager.h"

void UAshenLevelStreamingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveLoadedLevels.Empty();
	UE_LOG(LogTemp, Warning, TEXT("UAshenLevelStreamingSubsystem: Level streaming manager initialized."));
}

void UAshenLevelStreamingSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenLevelStreamingSubsystem::LoadLevelStream(FName LevelName)
{
	if (LevelName == NAME_None || ActiveLoadedLevels.Contains(LevelName)) return;

	PendingLoadLevel = LevelName;
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = FName("HandleLevelLoaded");
	LatentInfo.Linkage = 0;
	LatentInfo.UUID = FMath::Rand();

	UGameplayStatics::LoadStreamLevel(GetWorld(), LevelName, true, true, LatentInfo);
}

void UAshenLevelStreamingSubsystem::UnloadLevelStream(FName LevelName)
{
	if (LevelName == NAME_None || !ActiveLoadedLevels.Contains(LevelName)) return;

	PendingUnloadLevel = LevelName;
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = FName("HandleLevelUnloaded");
	LatentInfo.Linkage = 0;
	LatentInfo.UUID = FMath::Rand();

	UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelName, LatentInfo, true);
}

void UAshenLevelStreamingSubsystem::HandleLevelLoaded()
{
	if (PendingLoadLevel != NAME_None)
	{
		ActiveLoadedLevels.AddUnique(PendingLoadLevel);
		OnLevelStreamingStateChanged.Broadcast(PendingLoadLevel, true);
		UE_LOG(LogTemp, Warning, TEXT("UAshenLevelStreamingSubsystem: Stream level '%s' loaded!"), *PendingLoadLevel.ToString());
		PendingLoadLevel = NAME_None;
	}
}

void UAshenLevelStreamingSubsystem::HandleLevelUnloaded()
{
	if (PendingUnloadLevel != NAME_None)
	{
		ActiveLoadedLevels.Remove(PendingUnloadLevel);
		OnLevelStreamingStateChanged.Broadcast(PendingUnloadLevel, false);
		UE_LOG(LogTemp, Warning, TEXT("UAshenLevelStreamingSubsystem: Stream level '%s' unloaded!"), *PendingUnloadLevel.ToString());
		PendingUnloadLevel = NAME_None;
	}
}

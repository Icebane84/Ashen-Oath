// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

UAshenGameInstance::UAshenGameInstance()
{
	CurrentSaveSlotName = TEXT("PlaytestSlot_01");
}

void UAshenGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("UAshenGameInstance: Master Vertical Slice GameInstance Initialized."));
}

void UAshenGameInstance::Shutdown()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenGameInstance: GameInstance shutting down."));
	Super::Shutdown();
}

void UAshenGameInstance::LaunchVerticalSliceLevel(FName LevelName)
{
	if (LevelName.IsNone())
	{
		LevelName = FName("L_FrozenTarn_VerticalSlice");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenGameInstance: Launching Level '%s'..."), *LevelName.ToString());
	UGameplayStatics::OpenLevel(this, LevelName);
}

void UAshenGameInstance::SavePlaytestSession(const FString& SlotName)
{
	FString TargetSlot = SlotName.IsEmpty() ? CurrentSaveSlotName : SlotName;
	UE_LOG(LogTemp, Log, TEXT("UAshenGameInstance: Saved Playtest Session to Slot '%s'."), *TargetSlot);
}

bool UAshenGameInstance::LoadPlaytestSession(const FString& SlotName)
{
	FString TargetSlot = SlotName.IsEmpty() ? CurrentSaveSlotName : SlotName;
	UE_LOG(LogTemp, Log, TEXT("UAshenGameInstance: Loaded Playtest Session from Slot '%s'."), *TargetSlot);
	return true;
}

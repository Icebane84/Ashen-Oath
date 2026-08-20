// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenUserWidget_PauseSettingsMenu.h"
#include "AshenAudioSubsystem.h"
#include "AshenSaveManager.h"
#include "Kismet/GameplayStatics.h"

void UAshenUserWidget_PauseSettingsMenu::ResumeGame()
{
	if (GetWorld())
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		OnActionExecuted.Broadcast(TEXT("ResumeGame"));
		UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PauseSettingsMenu: Gameplay unpaused."));
	}
}

void UAshenUserWidget_PauseSettingsMenu::SetMasterVolume(float Volume)
{
	MasterVolume = FMath::Clamp(Volume, 0.0f, 1.0f);
	OnActionExecuted.Broadcast(TEXT("SetMasterVolume"));
}

void UAshenUserWidget_PauseSettingsMenu::SaveAndExitToMainMenu()
{
	if (GetGameInstance())
	{
		if (UAshenSaveManager* SaveMgr = GetGameInstance()->GetSubsystem<UAshenSaveManager>())
		{
			SaveMgr->SaveGameData(TEXT("AutoSave"));
		}
	}

	OnActionExecuted.Broadcast(TEXT("SaveAndExitToMainMenu"));
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_PauseSettingsMenu: Game saved. Exiting to Main Menu."));

	if (GetWorld())
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName("L_MainMenu"));
	}
}

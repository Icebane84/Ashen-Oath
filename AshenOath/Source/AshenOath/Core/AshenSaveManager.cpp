// Copyright Phoenix Protocol. All rights reserved.

#include "AshenSaveManager.h"
#include "AshenSaveGame.h"
#include "AshenOath_DirectorSubsystem.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenOath_OathRegistryComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenVigilRegistry.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_StatsComponent.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "AshenOath_ManaComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenOathCharacter.h"
#include "QuestSystem.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

bool UAshenSaveManager::SaveGameData(FString SlotName)
{
	UAshenSaveGame* SaveObject = Cast<UAshenSaveGame>(UGameplayStatics::CreateSaveGameObject(UAshenSaveGame::StaticClass()));
	if (!SaveObject) return false;

	UAshenOath_DirectorSubsystem* Director = GetGameInstance()->GetSubsystem<UAshenOath_DirectorSubsystem>();
	if (!Director) return false;

	APawn* PlayerPawn = Director->GetPlayerPawn();
	if (PlayerPawn && PlayerPawn->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_StatsComponent* Stats = IAshenCharacterInterface::Execute_GetStatsComponent(PlayerPawn))
		{
			SaveObject->PlayerLevel = Stats->GetLevel();
			SaveObject->PlayerXP = Stats->GetExperience();
			SaveObject->PlayerVitality = Stats->GetVitality();
			SaveObject->PlayerStrength = Stats->GetStrength();
			SaveObject->PlayerDexterity = Stats->GetDexterity();
		}

		if (UAshenOath_InventoryComponent* Inv = IAshenCharacterInterface::Execute_GetInventoryComponent(PlayerPawn))
		{
			SaveObject->InventoryItems = Inv->GetInventoryItems();
		}

		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(PlayerPawn))
		{
			SaveObject->PlayerSanity = Sanity->GetCurrentSanity();
			SaveObject->PlayerResonance = Sanity->GetCurrentResonance();
		}

		if (UAshenOath_StaminaComponent* Stamina = IAshenCharacterInterface::Execute_GetStaminaComponent(PlayerPawn))
		{
			SaveObject->PlayerStamina = Stamina->GetCurrentStamina();
		}

		if (UAshenOath_ManaComponent* Mana = IAshenCharacterInterface::Execute_GetManaComponent(PlayerPawn))
		{
			SaveObject->PlayerMana = Mana->GetCurrentMana();
		}

		if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(PlayerPawn))
		{
			SaveObject->PlayerPoise = Poise->GetCurrentPoise();
		}

		if (AAshenOathCharacter* AshenChar = Cast<AAshenOathCharacter>(PlayerPawn))
		{
			SaveObject->PlayerSpawnPosition = AshenChar->SpawnPosition;
		}

		if (UAshenOath_OathRegistryComponent* OathReg = PlayerPawn->FindComponentByClass<UAshenOath_OathRegistryComponent>())
		{
			SaveObject->SavedOaths = OathReg->GetOaths();
			SaveObject->SavedOathBurden = OathReg->GetOathBurden();
		}

		if (UAshenOath_CurrencyComponent* Currency = PlayerPawn->FindComponentByClass<UAshenOath_CurrencyComponent>())
		{
			SaveObject->SavedEmbers = Currency->GetEmbers();
			SaveObject->SavedAsh = Currency->GetAsh();
		}
	}

	if (UQuestSystem* Quests = Director->GetQuestSystem())
	{
		SaveObject->ActiveQuests = Quests->GetActiveQuests();
	}

	if (UAshenSoulConstellationSubsystem* Kernel = GetGameInstance()->GetSubsystem<UAshenSoulConstellationSubsystem>())
	{
		SaveObject->SavedStateVector = Kernel->GetStateVector();
		SaveObject->SavedDespair = Kernel->GetDespairLevel();
	}

	if (UAshenVigilRegistry* Vigils = GetGameInstance()->GetSubsystem<UAshenVigilRegistry>())
	{
		SaveObject->SavedVigils = Vigils->GetVigils();
	}

	return UGameplayStatics::SaveGameToSlot(SaveObject, SlotName, 0);
}

bool UAshenSaveManager::LoadGameData(FString SlotName)
{
	if (!UGameplayStatics::DoesSaveGameExist(SlotName, 0)) return false;

	UAshenSaveGame* SaveObject = Cast<UAshenSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	if (!SaveObject) return false;

	UAshenOath_DirectorSubsystem* Director = GetGameInstance()->GetSubsystem<UAshenOath_DirectorSubsystem>();
	if (!Director) return false;

	APawn* PlayerPawn = Director->GetPlayerPawn();
	if (PlayerPawn && PlayerPawn->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_StatsComponent* Stats = IAshenCharacterInterface::Execute_GetStatsComponent(PlayerPawn))
		{
			Stats->SetVitality(SaveObject->PlayerVitality);
			Stats->SetStrength(SaveObject->PlayerStrength);
			Stats->SetDexterity(SaveObject->PlayerDexterity);
			Stats->LoadStatsState(SaveObject->PlayerLevel, SaveObject->PlayerXP);
		}

		if (UAshenOath_InventoryComponent* Inv = IAshenCharacterInterface::Execute_GetInventoryComponent(PlayerPawn))
		{
			Inv->LoadInventoryState(SaveObject->InventoryItems);
		}

		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(PlayerPawn))
		{
			Sanity->SetCurrentSanity(SaveObject->PlayerSanity);
			Sanity->SetCurrentResonance(SaveObject->PlayerResonance);
		}

		if (UAshenOath_StaminaComponent* Stamina = IAshenCharacterInterface::Execute_GetStaminaComponent(PlayerPawn))
		{
			Stamina->SetCurrentStamina(SaveObject->PlayerStamina);
		}

		if (UAshenOath_ManaComponent* Mana = IAshenCharacterInterface::Execute_GetManaComponent(PlayerPawn))
		{
			Mana->SetCurrentMana(SaveObject->PlayerMana);
		}

		if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(PlayerPawn))
		{
			Poise->SetCurrentPoise(SaveObject->PlayerPoise);
		}

		if (AAshenOathCharacter* AshenChar = Cast<AAshenOathCharacter>(PlayerPawn))
		{
			AshenChar->SpawnPosition = SaveObject->PlayerSpawnPosition;
			AshenChar->SetActorLocation(AshenChar->SpawnPosition);
		}

		if (UAshenOath_OathRegistryComponent* OathReg = PlayerPawn->FindComponentByClass<UAshenOath_OathRegistryComponent>())
		{
			OathReg->LoadOathState(SaveObject->SavedOaths, SaveObject->SavedOathBurden);
		}

		if (UAshenOath_CurrencyComponent* Currency = PlayerPawn->FindComponentByClass<UAshenOath_CurrencyComponent>())
		{
			Currency->LoadCurrencyState(SaveObject->SavedEmbers, SaveObject->SavedAsh);
		}
	}

	if (UQuestSystem* Quests = Director->GetQuestSystem())
	{
		Quests->LoadQuestState(SaveObject->ActiveQuests);
	}

	if (UAshenSoulConstellationSubsystem* Kernel = GetGameInstance()->GetSubsystem<UAshenSoulConstellationSubsystem>())
	{
		Kernel->LoadSavedState(SaveObject->SavedStateVector, SaveObject->SavedDespair);
	}

	if (UAshenVigilRegistry* Vigils = GetGameInstance()->GetSubsystem<UAshenVigilRegistry>())
	{
		Vigils->LoadVigilState(SaveObject->SavedVigils);
	}

	return true;
}


bool UAshenSaveManager::HasSaveData(FString SlotName) const
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, 0);
}

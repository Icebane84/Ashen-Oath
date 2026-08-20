// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AshenSoulStateVector.h"
#include "AshenOath_QuickbarComponent.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_OathRegistryComponent.h"
#include "AshenVigilRegistry.h"
#include "AshenQuestTypes.h"
#include "AshenSaveGame.generated.h"

/**
 * UAshenSaveGame
 *
 * Native USaveGame object holding full binary serialized playtest state:
 *   - Player Character Stats (Level, XP, Vitality, Strength, Dexterity, Spawn Position)
 *   - Core Resources (Sanity, Resonance, Stamina, Mana, Poise)
 *   - FSoulStateVector & Despair level
 *   - Inventory, Quickbar slots, Currency (Embers & Ash)
 *   - Oath Records & Vigil Records
 *   - Active Quests
 *   - Unlocked identity tree perks
 */
UCLASS()
class ASHENOATH_API UAshenSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UAshenSaveGame();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame")
	FString SaveSlotName = TEXT("PlaytestSlot_01");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame")
	int32 UserIndex = 0;

	// --- Player Stats & Attributes ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	int32 PlayerLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerXP = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerVitality = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerStrength = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerDexterity = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerSanity = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerResonance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerStamina = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerMana = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	float PlayerPoise = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Player")
	FVector PlayerSpawnPosition = FVector::ZeroVector;

	// --- Inventory & Economy ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Inventory")
	TArray<FAshenItemData> InventoryItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Quickbar")
	TArray<FQuickbarItemSlot> SavedQuickSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Economy")
	float SavedEmbers = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Economy")
	float SavedAsh = 0.0f;

	// --- Oaths & Vigils ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Oaths")
	TArray<FOathRecord> SavedOaths;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Oaths")
	float SavedOathBurden = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Vigils")
	TArray<FVigilRecord> SavedVigils;

	// --- Quests ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Quests")
	TArray<FAshenQuestRuntime> ActiveQuests;

	// --- Soul Constellation & Perks ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Soul")
	FSoulStateVector SavedStateVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Soul")
	float SavedDespair = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame|Perks")
	TSet<FName> SavedActivePerks;
};

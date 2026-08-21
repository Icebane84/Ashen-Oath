// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCodexArchiveTypes.generated.h"

/**
 * ECodexCategory
 * 
 * Defines the classification of an archival codex entry.
 */
UENUM(BlueprintType)
enum class ECodexCategory : uint8
{
	BossAnatomy UMETA(DisplayName = "Boss Anatomy & Titan Physiology"),
	AncientRelics UMETA(DisplayName = "Ancient Relics & Sacred Artifacts"),
	FactionHistory UMETA(DisplayName = "Sundered Factions & Order of the Pyre"),
	CompanionMemories UMETA(DisplayName = "Companion Personal Chronicles"),
	WorldGeography UMETA(DisplayName = "Ashlands Geography & Ruins")
};

/**
 * ERelicRarityTier
 * 
 * Defines the historical significance and crafting potential of a relic.
 */
UENUM(BlueprintType)
enum class ERelicRarityTier : uint8
{
	CommonRelic UMETA(DisplayName = "Common Relic (Faded Inscriptions)"),
	RareArtifact UMETA(DisplayName = "Rare Artifact (Runic Resonance)"),
	SacredHeirloom UMETA(DisplayName = "Sacred Heirloom (White Flame Inscribed)"),
	TitanCoreRelic UMETA(DisplayName = "Titan Core Relic (Nightsteel Essence)")
};

/**
 * FCodexEntry
 * 
 * Represents a single archival lore entry in the Ashen Codex.
 */
USTRUCT(BlueprintType)
struct FCodexEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	FName EntryId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	ECodexCategory Category = ECodexCategory::BossAnatomy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	FText Title = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	FText LoreText = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	bool bIsUnlocked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	float DiscoveryTimestamp = 0.0f;
};

/**
 * FHistoricalRelicInspectionData
 * 
 * 3D examination state for an ancient relic.
 */
USTRUCT(BlueprintType)
struct FHistoricalRelicInspectionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	FName RelicId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	ERelicRarityTier Rarity = ERelicRarityTier::RareArtifact;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	float InscriptionDecodedPercent = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	float ResonanceFrequencyHz = 528.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Archive")
	bool bSecretRevealed = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCodexEntryUnlocked, const FName&, EntryId, ECodexCategory, Category);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRelicInspected, const FName&, RelicId, float, DecodedPercent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionMarginaliaAppended, const FName&, EntryId, const FName&, CompanionId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCodexRepositoryVisibilityChanged, bool, bIsVisible);

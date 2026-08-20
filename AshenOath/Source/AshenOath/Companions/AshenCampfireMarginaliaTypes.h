// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCampfireMarginaliaTypes.generated.h"

// -----------------------------------------------------------------------------------
// CAMPFIRE MARGINALIA ENUMERATIONS (JOURNAL-SPEC-055 / CMM-001)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EMarginaliaAuthor : uint8
{
	Kaelen   UMETA(DisplayName = "Kaelen (Core Prose & Ink Scars)"),
	Garrett  UMETA(DisplayName = "Garrett (Rigid Charcoal & Tactical Cross-Outs)"),
	Serafina UMETA(DisplayName = "Serafina (Flowing Brown Ink & Pressed Silverleaf)")
};

UENUM(BlueprintType)
enum class EMarginAnchorSlot : uint8
{
	LeftMargin_Upper   UMETA(DisplayName = "Left Margin Upper (Max 90 chars)"),
	LeftMargin_Lower   UMETA(DisplayName = "Left Margin Lower (Max 90 chars)"),
	RightMargin_Upper  UMETA(DisplayName = "Right Margin Upper (Max 90 chars)"),
	RightMargin_Lower  UMETA(DisplayName = "Right Margin Lower (Max 90 chars)"),
	FooterAnchor       UMETA(DisplayName = "Footer Anchor (Max 140 chars)"),
	InlineCrossout     UMETA(DisplayName = "Inline Text Scratch-out Overlay")
};

UENUM(BlueprintType)
enum class EInkDensityState : uint8
{
	Pristine,
	LightFading,
	HeavyBleed,
	CharcoalScratched,
	TearStained
};

// -----------------------------------------------------------------------------------
// CAMPFIRE MARGINALIA STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Visual Styling Parameters for Penmanship & Ink Shaders.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FMarginaliaVisualParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal|Visuals")
	FGameplayTag FontToken;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal|Visuals")
	float InkDensity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal|Visuals")
	float JitterIntensity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal|Visuals")
	FLinearColor InkColor = FLinearColor(0.1f, 0.1f, 0.1f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal|Visuals")
	FString ScratchOutTargetId;
};

/**
 * A Single Multi-Author Marginalia Entry.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FMarginaliaEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FString EntryId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	EMarginaliaAuthor Author = EMarginaliaAuthor::Kaelen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	EMarginAnchorSlot AnchorSlot = EMarginAnchorSlot::RightMargin_Lower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FString InscriptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FGameplayTag InscriptionTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FMarginaliaVisualParams VisualParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FString TargetMemoryId;
};

/**
 * Ingest Packet for Campfire Rest Evaluation.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenMarginaliaIngestPacket
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FString RequestId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FName SanctuaryId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FCanonicalSoulStateVector SoulStateSnapshot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	TArray<FString> WitnessedImprints;
};

// -----------------------------------------------------------------------------------
// MASTER MARGINALIA MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarginaliaBatchGenerated, const TArray<FMarginaliaEntry>&, GeneratedEntries);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMarginaliaCrossoutApplied, const FString&, TargetEntryId, const FString&, ScratchOutText);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParchmentJitterUpdated, float, JitterIntensity, float, InkBleedScalar);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBotanicalPressed, FName, BotanicalHerbId);

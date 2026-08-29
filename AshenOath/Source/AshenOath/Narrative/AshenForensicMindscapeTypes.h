// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenForensicMindscapeTypes.generated.h"

/**
 * EForensicClueCategory
 * 
 * Classification of evidence gathered in the overland.
 */
UENUM(BlueprintType)
enum class EForensicClueCategory : uint8
{
	PhysicalAutopsyEvidence    UMETA(DisplayName = "Physical Autopsy (Wound Angle, Burn Residue, Caliber)"),
	CompanionTestimony         UMETA(DisplayName = "Companion Testimony (Garrett Observation vs Serafina Dogma)"),
	HistoricalRunicInscription UMETA(DisplayName = "Historical Runic Inscription (Ancient Stelae & Chronicles)"),
	BotanicalChemicalSample    UMETA(DisplayName = "Botanical / Chemical Sample (Toxins, Spores, Glands)")
};

/**
 * EMemoryReconstructionState
 * 
 * Investigative status of a Memory Palace case.
 */
UENUM(BlueprintType)
enum class EMemoryReconstructionState : uint8
{
	UnsolvedFragments  UMETA(DisplayName = "Unsolved Fragments (Clues Gathering)"),
	DeductionInProgress UMETA(DisplayName = "Deduction In Progress (Pins Connected, S < 0.85)"),
	ReconstructedTruth UMETA(DisplayName = "Reconstructed Truth (S >= 0.85, Reenactment Unlocked)")
};

/**
 * EForgottenCaseOutcome
 * 
 * Reward unlocked upon solving a forensic mindscape memory.
 */
UENUM(BlueprintType)
enum class EForgottenCaseOutcome : uint8
{
	SanityCatharsisPurge   UMETA(DisplayName = "Psychic Catharsis (+50 Sanity Recovered)"),
	FactionAutopsyMastery  UMETA(DisplayName = "Faction Autopsy Mastery (+25% Crit, +40% Poise Dmg)"),
	CompanionEnlightenment UMETA(DisplayName = "Companion Enlightenment (Contradiction Resolved)")
};

/**
 * FForensicClueRecord
 * 
 * Metadata for a single discovered evidence item.
 */
USTRUCT(BlueprintType)
struct FForensicClueRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	FName ClueId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	EForensicClueCategory Category = EForensicClueCategory::PhysicalAutopsyEvidence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	FText ClueTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	FText ClueDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	float ReliabilityWeight = 1.0f; // 0.1 to 1.0
};

/**
 * FMemoryPalaceDeductionBoard
 * 
 * Deduction board state inside the Memory Palace.
 */
USTRUCT(BlueprintType)
struct FMemoryPalaceDeductionBoard
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	FName CaseId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	EMemoryReconstructionState State = EMemoryReconstructionState::UnsolvedFragments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	TArray<FName> PinnedClueIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	float SynthesisIndex = 0.0f; // 0.0 to 1.0
};

/**
 * FReconstructedMemoryResult
 * 
 * Output metrics from solving a forensic case.
 */
USTRUCT(BlueprintType)
struct FReconstructedMemoryResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	FName CaseId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	bool bCaseSolved = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	float SanityRestored = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	float FactionCritDamageBonus = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic")
	FText EpiphanyLoreSummary;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnForensicClueDiscovered, FName, ClueId, const FForensicClueRecord&, ClueData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryDeductionBoardUpdated, FName, CaseId, float, SynthesisIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryPalaceCaseSolved, FName, CaseId, const FReconstructedMemoryResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionContradictionExposed, FName, CompanionId, FText, ContradictionText);

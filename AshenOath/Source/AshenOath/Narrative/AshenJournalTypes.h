// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenJournalTypes.generated.h"

UENUM(BlueprintType)
enum class EJournalEventType : uint8
{
	NewEntryCompiled,
	CompanionMarginaliaAdded,
	MemoryRevisitedAndReframed,
	PsychologicalDistortionApplied
};

USTRUCT(BlueprintType)
struct FJournalPerspective
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FName AuthorName; // "Kaelen", "Garrett", "Serafina"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FText InterpretationText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	float EmotionalStateValence = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FName TrustContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FDateTime Timestamp;
};

USTRUCT(BlueprintType)
struct FJournalEvent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FGuid SourceImprintGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FName MemoryNodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	EJournalEventType EventType = EJournalEventType::NewEntryCompiled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FText CanonicalFactText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	TArray<FJournalPerspective> Perspectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	uint8 ActiveLensIndex = 0; // 0: Accountability, 1: Grace, 2: Utility

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	float KaelenSanityAtTimeOfWriting = 1.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJournalEventDispatched, const FJournalEvent&, JournalEvent);

/**
 * EForensicMarginaliaAuthor
 * 
 * Author of the handwritten marginalia commentary in the Campfire Journal.
 */
UENUM(BlueprintType)
enum class EForensicMarginaliaAuthor : uint8
{
	Kaelen      UMETA(DisplayName = "Kaelen (Black Iron Carbon Ink - Martial Analysis)"),
	Garrett     UMETA(DisplayName = "Garrett (Verdant Gall Ink - Tactical Skepticism)"),
	Serafina    UMETA(DisplayName = "Serafina (Golden Radiant Ink - Spiritual Reflection)"),
	SystemCanon UMETA(DisplayName = "System Canon (Illuminated Chronicle Text)")
};

/**
 * EJournalEntryCategory
 * 
 * Category of chronicle entries in the Campfire Codex.
 */
UENUM(BlueprintType)
enum class EJournalEntryCategory : uint8
{
	ScenarioChronicle   UMETA(DisplayName = "Scenario Historical Chronicle (1-10)"),
	SootProvenanceLedger UMETA(DisplayName = "Soot Provenance & Weapon Wear Ledger"),
	CompanionTraumaLog  UMETA(DisplayName = "Companion Psychological Trauma Log"),
	ConsequenceEpilogue UMETA(DisplayName = "Consequence Resolution & Epilogue")
};

/**
 * ECampfireReflectionMood
 * 
 * Ambient emotional mood of the companions during campfire contemplation.
 */
UENUM(BlueprintType)
enum class ECampfireReflectionMood : uint8
{
	SomberSilence   UMETA(DisplayName = "Somber Silence (Post-Trauma Mourning)"),
	TemperedResolve UMETA(DisplayName = "Tempered Resolve (Strategic Deliberation)"),
	SharedCatharsis UMETA(DisplayName = "Shared Catharsis (High Trust Healing)")
};

/**
 * FForensicJournalEntry
 * 
 * A single entry in the Grand Campaign Forensic Journal.
 */
USTRUCT(BlueprintType)
struct FForensicJournalEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	int32 ScenarioIndex = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FString ScenarioTitle = TEXT("The Bleeding Waystation");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FText CanonicalSummary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FText KaelenMarginalia;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FText GarrettMarginalia;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FText SerafinaMarginalia;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	float RecordedDebt01 = 0.10f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	float RecordedSootMicrons = 12.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	bool bUnlocked = false;
};

// Multicast Delegates for Forensic Campfire Journal (Master Batch #141)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJournalEntrySelected, int32, ScenarioIndex, const FForensicJournalEntry&, Entry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMarginaliaDeciphered, EForensicMarginaliaAuthor, Author, const FText&, NoteText);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCampfireMoodChanged, ECampfireReflectionMood, NewMood);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSootLedgerBurnished, float, RemainingSootMicrons);

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenLivingJournalConsequenceTypes.generated.h"

UENUM(BlueprintType)
enum class EJournalPerspectiveType : uint8
{
	SolitaryMartyrdom   UMETA(DisplayName = "Solitary Martyrdom (Dark Kill)"),
	TripartiteSynarchy  UMETA(DisplayName = "Tripartite Synarchy (Sync Finisher)")
};

UENUM(BlueprintType)
enum class EConstellationNodeVisual : uint8
{
	Unresolved          UMETA(DisplayName = "Unresolved Node"),
	GoldWhiteLeyConduit UMETA(DisplayName = "Gold-White Ley Conduit (Synarchy)"),
	ObsidianFracture    UMETA(DisplayName = "Obsidian Fracture (Martyrdom)")
};

USTRUCT(BlueprintType)
struct FTacticalFramePerkData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FName MonsterArchetype = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	float CalloutTimeAdvance = 1.0f; // Seconds earlier Garrett spots weakpoint

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	float SunPulseHitboxExpansion = 1.35f; // +35% hitbox radius for Serafina

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	bool bIsPerkUnlocked = false;
};

USTRUCT(BlueprintType)
struct FJournalResolutionEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FName BestiaryEntryID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	EJournalPerspectiveType Perspective = EJournalPerspectiveType::TripartiteSynarchy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FString KaelenEntryText = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FString GarrettMarginNote = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FString SerafinaMarginNote = TEXT("");
};

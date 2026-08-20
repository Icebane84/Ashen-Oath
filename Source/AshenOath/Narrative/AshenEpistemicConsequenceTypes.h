// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenEpistemicConsequenceTypes.generated.h"

UENUM(BlueprintType)
enum class EConsequenceProfileTier : uint8
{
	Common    UMETA(DisplayName = "Tier I: Common (Skirmish Mob - Journal + Perk)"),
	Rare      UMETA(DisplayName = "Tier II: Rare (Elite Symbiote - AI Frame + Cartographer)"),
	Milestone UMETA(DisplayName = "Tier III: Milestone (Boss/Ash-Casket - 5-Layer Full Convergence)")
};

USTRUCT(BlueprintType)
struct FCanonicalCombatEvent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	FGuid EventID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	FName EncounterID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	FName FinisherUsed = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	EConsequenceProfileTier ProfileTier = EConsequenceProfileTier::Common;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	bool bWasTripartiteSynarchy = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	float RecordedMutualTrust = 0.85f;
};

USTRUCT(BlueprintType)
struct FTripartiteInterpretationPackage
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	FString KaelenSubjectiveProse = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	FString GarrettTacticalNote = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Epistemic")
	FString SerafinaGraceLeaf = TEXT("");
};

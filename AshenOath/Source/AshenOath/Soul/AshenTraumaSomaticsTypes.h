// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenTraumaSomaticsTypes.generated.h"

/**
 * ETraumaSomaticStage
 * 
 * Clinical stages of Kaelen's visible somatic and psychological trauma progression.
 */
UENUM(BlueprintType)
enum class ETraumaSomaticStage : uint8
{
	Stage0_BaselinePristine UMETA(DisplayName = "Stage 0: Pristine / Uncorrupted"),
	Stage1_SubcutaneousTaint UMETA(DisplayName = "Stage 1: Subcutaneous Vein Darkening (Debt 0.25-0.50)"),
	Stage2_VascularCrisis    UMETA(DisplayName = "Stage 2: Vascular Crisis & Sclera Red-Out (Debt 0.50-0.75)"),
	Stage3_ShatteredVessel   UMETA(DisplayName = "Stage 3: Shattered Vessel / Black Blood Surge (Debt > 0.75)")
};

/**
 * EBladeSootDecayProfile
 * 
 * Rate of procedural soot and ash deposition on the Oathbringer Greatsword.
 */
UENUM(BlueprintType)
enum class EBladeSootDecayProfile : uint8
{
	CleanPolishedSteel UMETA(DisplayName = "Clean Polished Steel (0.00-0.15)"),
	SmokedEdge         UMETA(DisplayName = "Smoked Edge / Ash Coating (0.15-0.50)"),
	CharredBlackSteel  UMETA(DisplayName = "Charred Black Steel (0.50-0.80)"),
	SuperheatedSlag    UMETA(DisplayName = "Superheated Thermal Slag (0.80-1.00)")
};

/**
 * FTraumaSomaticStateVector
 * 
 * Real-time biological and physical telemetry driving somatic materials and audio.
 */
USTRUCT(BlueprintType)
struct FTraumaSomaticStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Somatics")
	ETraumaSomaticStage SomaticStage = ETraumaSomaticStage::Stage0_BaselinePristine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Somatics")
	float VeinCorruptionScalar = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Somatics")
	float ScleraRednessScalar = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Somatics")
	float SkinPallorScalar = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Somatics")
	float HeartRateBPM = 60.0f; // 60 to 170 BPM

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Somatics")
	float BladeSootScalar = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Somatics")
	float BladeMicroNickCount = 0.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSomaticStageChanged, ETraumaSomaticStage, NewStage, float, VeinCorruption);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBladeSootUpdated, float, SootScalar, EBladeSootDecayProfile, SootProfile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeartRateShifted, float, NewBPM);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBladeCleanedAtCampfire, float, RecoveredResolve);

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenBossIncursionTypes.generated.h"

UENUM(BlueprintType)
enum class EBossPhaseState : uint8
{
	Phase1_TacticalDuel     UMETA(DisplayName = "Phase 1: Tactical Posture Duel"),
	Phase2_ChasmFracture    UMETA(DisplayName = "Phase 2: Null-Zone Chasm Fracture"),
	Phase3_ApexCataclysm    UMETA(DisplayName = "Phase 3: Apex Void Cataclysm"),
	Phase_StaggeredVulnerable UMETA(DisplayName = "Staggered Vulnerable (Trial of Will Window)"),
	Phase_Defeated          UMETA(DisplayName = "Boss Defeated")
};

UENUM(BlueprintType)
enum class EArenaHazardType : uint8
{
	VoidFissureChasm  UMETA(DisplayName = "Void Fissure (Traversable via Light Bridge)"),
	FallingMasonry    UMETA(DisplayName = "Falling Masonry (Physical Impact Zone)"),
	DesecratedSludge  UMETA(DisplayName = "Desecrated Sludge (Movement Slow & Posture Drain)")
};

UENUM(BlueprintType)
enum class EStaggerExecutionType : uint8
{
	SoloMartyrStrike       UMETA(DisplayName = "Solo Martyr Strike"),
	TripartiteResonantCleave UMETA(DisplayName = "Tripartite Resonant Cleave"),
	WhitePyreDisintegration UMETA(DisplayName = "White Pyre Disintegration")
};

USTRUCT(BlueprintType)
struct FBossEncounterPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	FName BossId = FName(TEXT("Malakor_The_Sundered_Herald"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	float MaxHealth = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	float CurrentHealth = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	float MaxPoise = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	float CurrentPoise = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	EBossPhaseState Phase = EBossPhaseState::Phase1_TacticalDuel;
};

USTRUCT(BlueprintType)
struct FArenaHazardZoneData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	FVector Location = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	float Radius = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	EArenaHazardType HazardType = EArenaHazardType::VoidFissureChasm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	bool bIsHazardActive = false;
};

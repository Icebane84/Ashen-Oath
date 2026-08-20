// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenTraumaEnemyMatrixTypes.generated.h"

UENUM(BlueprintType)
enum class ETEMEncounterTier : uint8
{
	Pressure   UMETA(DisplayName = "Tier I: Pressure (Session Buffer)"),
	Trauma     UMETA(DisplayName = "Tier II: Trauma (Coping Disruption)"),
	Revelation UMETA(DisplayName = "Tier III: Revelation (Apex Boss)")
};

USTRUCT(BlueprintType)
struct FAdversarialArgument
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TEM")
	FName MonsterID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TEM")
	FName TargetedHero = NAME_None; // e.g. Kaelen

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TEM")
	FString CoreLieTargeted = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TEM")
	FString PhilosophicalThesis = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | TEM")
	ETEMEncounterTier Tier = ETEMEncounterTier::Pressure;
};

USTRUCT(BlueprintType)
struct FTripartiteResourceState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Economy")
	float KaelenCorruption = 0.0f; // 0.0 to 1.0 (Shadow Mark)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Economy")
	float SerafinaBurnout = 0.0f; // 0.0 to 1.0 (Empathic Burnout)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Economy")
	float GarrettSanityPosture = 1.0f; // 1.0 (Composed) down to 0.0 (Cynical Isolation)
};

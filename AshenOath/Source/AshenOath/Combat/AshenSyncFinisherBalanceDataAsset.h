// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AshenSyncFinisherBalanceDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FSyncedShadowStrikeBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "100.0", ClampMax = "2000.0"))
	float BaseDamage = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "1.0", ClampMax = "3.5"))
	float StaggeredMultiplier = 1.8f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "0.05", ClampMax = "0.60"))
	float GarrettFatigueCost = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "200.0", ClampMax = "1200.0"))
	float Radius = 500.0f;
};

USTRUCT(BlueprintType)
struct FSyncedHolyBurstBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "100.0", ClampMax = "1500.0"))
	float BaseDamage = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "10.0", ClampMax = "200.0"))
	float SanityAndHealthHeal = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "0.05", ClampMax = "0.60"))
	float SerafinaFatigueCost = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "300.0", ClampMax = "1500.0"))
	float Radius = 650.0f;
};

USTRUCT(BlueprintType)
struct FTripartiteZenithBalancing
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "500.0", ClampMax = "10000.0"))
	float BaseDamage = 2500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "100.0", ClampMax = "1500.0"))
	float PoiseDamage = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "0.05", ClampMax = "0.50"))
	float TimeDilationScale = 0.10f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "0.10", ClampMax = "0.60"))
	float CompanionFatigueCost = 0.35f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finisher Balancing", meta = (ClampMin = "500.0", ClampMax = "2500.0"))
	float Radius = 1200.0f;
};

/**
 * UAshenSyncFinisherBalanceDataAsset
 * Primary DataAsset exposing live editor balancing parameters for all dual and tripartite synchronized finishers.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSyncFinisherBalanceDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sync Finishers | Shadow Strike (Kaelen + Garrett)")
	FSyncedShadowStrikeBalancing ShadowStrikeParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sync Finishers | Holy Burst (Kaelen + Serafina)")
	FSyncedHolyBurstBalancing HolyBurstParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sync Finishers | Tripartite Zenith (All 3)")
	FTripartiteZenithBalancing TripartiteZenithParams;

	FSyncedShadowStrikeBalancing GetClampedShadowStrike() const;
	FSyncedHolyBurstBalancing GetClampedHolyBurst() const;
	FTripartiteZenithBalancing GetClampedTripartiteZenith() const;
};

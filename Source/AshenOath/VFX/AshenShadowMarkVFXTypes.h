// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenShadowMarkVFXTypes.generated.h"

UENUM(BlueprintType)
enum class EShadowSeepagePhase : uint8
{
	Dormant       UMETA(DisplayName = "Phase 0: Dormant (< 0.10)"),
	VeinGlow      UMETA(DisplayName = "Phase 1: Violet Vein Glow (0.10 - 0.35)"),
	BileSeepage   UMETA(DisplayName = "Phase 2: Nyx Bile Seepage (0.35 - 0.70)"),
	CrimsonSurge  UMETA(DisplayName = "Phase 3: Crimson Static Discharge (>= 0.70)")
};

USTRUCT(BlueprintType)
struct FShadowMarkEmitterMetrics
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | VFX")
	float VeinSpawnRate = 5.0f; // 5 to 120

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | VFX")
	float NormalOffset = 0.1f; // 0.1 to 1.5 (Capped at 2.0)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | VFX")
	float BileRibbonSpawnRate = 0.0f; // 0 to 35

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | VFX")
	float CrimsonSparksSpawnRate = 0.0f; // 0 to 250

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | VFX")
	float CurlNoiseStrength = 10.0f; // 10 to 450
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenPsychicStrainTypes.generated.h"

UENUM(BlueprintType)
enum class ETransferenceStrainStage : uint8
{
	Stable        UMETA(DisplayName = "Stable"),
	Flickering    UMETA(DisplayName = "Flickering"),
	Fractured     UMETA(DisplayName = "Fractured"),
	Catastrophic  UMETA(DisplayName = "Catastrophic")
};

USTRUCT(BlueprintType)
struct FNightmareIncursionState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nightmare")
	float IncursionIntensity = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nightmare")
	bool bIsIncursionActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nightmare")
	int32 ActiveRiftCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nightmare")
	float RealityStabilityIndex = 1.0f; // 1.0 down to 0.0
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenEmpathicNovaTypes.generated.h"

UENUM(BlueprintType)
enum class ENovaFinisherState : uint8
{
	Inactive    UMETA(DisplayName = "Inactive"),
	Charging    UMETA(DisplayName = "Charging / Resonance Build"),
	Executing   UMETA(DisplayName = "Executing / Resonant Execution"),
	Recovery    UMETA(DisplayName = "Recovery / Imprint Reset")
};

USTRUCT(BlueprintType)
struct FEmpathicNovaMetrics
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nova")
	float MutualTrust = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nova")
	float IntegrationDebt = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nova")
	float SerafinaBurnout = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nova")
	float KaelenCorruption = 0.0f; // 0.0 to 1.0
};

USTRUCT(BlueprintType)
struct FHapticFrictionProfile
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Haptics")
	int32 TriggerResistance = 180; // 180 to 255

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Haptics")
	float LeftFrequencyHz = 30.0f; // 20 to 40 Hz (Shadow Mark)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Haptics")
	float RightFrequencyHz = 180.0f; // 150 to 200 Hz (White Flame)
};

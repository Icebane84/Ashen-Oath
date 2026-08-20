// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenWeatherAtmosphereTypes.generated.h"

UENUM(BlueprintType)
enum class EWeatherState : uint8
{
	ClearEmber     UMETA(DisplayName = "Clear Ember"),
	AshBlizzard    UMETA(DisplayName = "Ash Blizzard"),
	VoidMiasma     UMETA(DisplayName = "Void Miasma"),
	PsychicStorm   UMETA(DisplayName = "Psychic Storm")
};

USTRUCT(BlueprintType)
struct FWeatherAtmosphereData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weather")
	EWeatherState CurrentWeather = EWeatherState::ClearEmber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weather")
	float AtmosphericToxicity = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weather")
	float WindVelocity = 100.0f; // uu/s

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weather")
	FVector WindDirection = FVector(1, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weather")
	float VisibilityRange = 5000.0f; // uu
};

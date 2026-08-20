// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEnvironmentalWeatherSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenWeatherState : uint8
{
	ClearCalm       UMETA(DisplayName = "Clear Calm"),
	LightFlurry     UMETA(DisplayName = "Light Flurry"),
	HeavyBlizzard   UMETA(DisplayName = "Heavy Blizzard"),
	MindscapeStorm  UMETA(DisplayName = "Mindscape Storm")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherStateChangedSignature, EAshenWeatherState, NewWeatherState, float, WindIntensity);

/**
 * UAshenEnvironmentalWeatherSubsystem
 *
 * World subsystem driving dynamic environmental weather across Frozen Tarn:
 * Adjusts blizzard wind velocities, particle snow densities, and atmospheric fog distances.
 */
UCLASS()
class ASHENOATH_API UAshenEnvironmentalWeatherSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Weather")
	void SetWeatherState(EAshenWeatherState NewState);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Weather")
	EAshenWeatherState CurrentWeatherState = EAshenWeatherState::ClearCalm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Weather")
	float CurrentWindIntensity = 0.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Weather|Events")
	FOnWeatherStateChangedSignature OnWeatherStateChanged;
};

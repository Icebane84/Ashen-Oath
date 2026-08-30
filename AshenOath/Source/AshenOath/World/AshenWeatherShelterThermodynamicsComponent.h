// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWeatherShelterThermodynamicsComponent.generated.h"

class UAshenSoulPublisher;

UENUM(BlueprintType)
enum class EAshenShelterTier : uint8
{
	Wilderness    UMETA(DisplayName = "Unsheltered Wilderness (-2.5 HP/s, +0.02 Debt/s)"),
	CavernCover   UMETA(DisplayName = "Cavern Cover (0.0 HP/s Neutral)"),
	HavenBrazier  UMETA(DisplayName = "Haven Brazier (+100% Immunity, -0.05 Debt/s)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnThermodynamicShelterTierChanged, EAshenShelterTier, OldTier, EAshenShelterTier, NewTier);

/**
 * UAshenWeatherShelterThermodynamicsComponent
 *
 * Manages 3-tier shelter thermodynamics and converts unsheltered environmental
 * exposure directly into canonical Integration Debt (D) via UAshenSoulPublisher.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherShelterThermodynamicsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherShelterThermodynamicsComponent();

	virtual void BeginPlay() override;

	/** Sets the current shelter tier and recalculates thermodynamic hazards */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Weather")
	void SetShelterTier(EAshenShelterTier NewTier);

	/** Simulates delta exposure, committing canonical Integration Debt to the publisher */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Weather")
	void TickEnvironmentalExposure(float DeltaTime);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Weather")
	EAshenShelterTier GetCurrentShelterTier() const { return CurrentShelterTier; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Weather")
	float GetEffectiveExposureRate() const;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Weather")
	FOnThermodynamicShelterTierChanged OnShelterTierChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Weather")
	EAshenShelterTier CurrentShelterTier = EAshenShelterTier::Wilderness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Weather", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float WildernessDebtAccumulationRate = 0.02f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Weather", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float HavenDebtPurgeRate = 0.05f;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};

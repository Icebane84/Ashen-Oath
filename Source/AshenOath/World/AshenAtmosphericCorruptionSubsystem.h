// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAtmosphericCorruptionSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenAtmosphericHazard : uint8
{
	None                 UMETA(DisplayName = "None (Clear Atmosphere)"),
	VoidFogDensity       UMETA(DisplayName = "Void Fog (Vision & Sanity Drain)"),
	AshBlizzardStorm     UMETA(DisplayName = "Ash Blizzard (Movement & Stamina Drain)"),
	AcidicMiasmaCloud    UMETA(DisplayName = "Acidic Miasma (Armor & Health Corrosion)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAtmosphericHazardTriggeredSignature, EAshenAtmosphericHazard, ActiveHazard, float, DamageOrDrainRate);

/**
 * UAshenAtmosphericCorruptionSubsystem
 *
 * World Subsystem spawning environmental hazards (Void fog, ash blizzards, acidic miasma).
 */
UCLASS()
class ASHENOATH_API UAshenAtmosphericCorruptionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Atmosphere")
	void SetActiveAtmosphericHazard(EAshenAtmosphericHazard NewHazard, float SeverityRate);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Atmosphere")
	EAshenAtmosphericHazard GetActiveHazard() const { return CurrentHazard; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Atmosphere|Events")
	FOnAtmosphericHazardTriggeredSignature OnAtmosphericHazardTriggered;

private:
	EAshenAtmosphericHazard CurrentHazard = EAshenAtmosphericHazard::None;
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionComboSynergyComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSynergyMeterChangedSignature, float, SynergyMeter, float, Multiplier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSynergySurgeTriggeredSignature, float, BonusDamage);

/**
 * UAshenCompanionComboSynergyComponent
 *
 * Tracks joint companion attacks to build a synergy meter (0–100%).
 * Reaching 100% enables a 1.5x damage Synergy Surge for 6 seconds.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionComboSynergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionComboSynergyComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Synergy")
	void RegisterCompanionHit(float SynergyPoints = 15.0f);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Synergy")
	bool TriggerSynergySurge();

	UFUNCTION(BlueprintPure, Category = "AshenOath|Synergy")
	float GetSynergyMeter() const { return CurrentSynergyMeter; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Synergy")
	float GetCurrentMultiplier() const { return CurrentMultiplier; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Synergy")
	float MaxSynergyMeter = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Synergy")
	float SurgeMultiplier = 1.5f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Synergy|Events")
	FOnSynergyMeterChangedSignature OnSynergyMeterChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Synergy|Events")
	FOnSynergySurgeTriggeredSignature OnSynergySurgeTriggered;

private:
	float CurrentSynergyMeter = 0.0f;
	float CurrentMultiplier = 1.0f;
	bool bSurgeActive = false;
};

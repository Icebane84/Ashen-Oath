// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenRelationalPostProcessAdapter.generated.h"

/**
 * UAshenRelationalPostProcessAdapter
 * 
 * Modulates post-processing based on relational fellowship:
 * - High Resonance (Psi >= 0.75): Warm hearthfire color temperature and subtle bloom
 * - Active Rupture / Low Flow: Cold blue desaturation and fringe isolation shadow
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelationalPostProcessAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates the target color temperature and saturation from TrioResonance */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Relational")
	void UpdateFellowshipGrading(float TrioResonance, ERelationalRuptureState RuptureState);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Relational")
	float GetCurrentColorTemperature() const { return CurrentTemperature; }

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Relational")
	float GetCurrentSaturation() const { return CurrentSaturation; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Relational")
	float WarmTemperatureK = 6500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Relational")
	float ColdTemperatureK = 4500.0f;

private:
	float CurrentTemperature = 6500.0f;
	float TargetTemperature = 6500.0f;

	float CurrentSaturation = 1.0f;
	float TargetSaturation = 1.0f;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticAIDirectorComponent.generated.h"

/**
 * UAshenSomaticAIDirectorComponent
 * 
 * Companion AI Director implementing Schmitt Trigger Hysteresis for spacing and callouts:
 * Upward Threshold (Enter High-Alert) = 0.30, Downward Threshold (Relax) = 0.18,
 * 3.0s state dwell lock, and 8.0s dialogue bark cooldown.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticAIDirectorComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Evaluates new somatic state through the hysteresis gate */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AI|Somatic")
	void UpdateSomaticState(const FSomaticState& SomaticState);

	/** Computes recommended companion combat formation spacing in Unreal Units */
	UFUNCTION(BlueprintPure, Category = "Ashen|AI|Somatic")
	float GetRecommendedFormationSpacing() const;

	/** Evaluates whether companion is permitted to trigger a predictive tactical bark */
	UFUNCTION(BlueprintCallable, Category = "Ashen|AI|Somatic")
	bool CanTriggerPredictiveBark(double CurrentTimeSeconds);

	UFUNCTION(BlueprintPure, Category = "Ashen|AI|Somatic")
	bool IsInHighAlertFormation() const { return bInHighAlertFormation; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Somatic")
	float UpwardAlertThreshold = 0.30f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Somatic")
	float DownwardRelaxThreshold = 0.18f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Somatic")
	float MinStateDwellSeconds = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Somatic")
	float BarkCooldownSeconds = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Somatic")
	float StandardSpacingUU = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Somatic")
	float TightSupportedSpacingUU = 250.0f;

private:
	bool bInHighAlertFormation = false;
	double LastStateTransitionTime = 0.0;
	double LastBarkTimestamp = 0.0;

	UPROPERTY()
	FSomaticState CurrentSomaticState;
};

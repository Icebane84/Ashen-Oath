// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenUserWidget_Scenario7CrucibleHUD.generated.h"

/**
 * UAshenUserWidget_Scenario7CrucibleHUD
 * 
 * UMG widget displaying caldera temperature, Heat Exhaustion gauge, stamina drain multiplier, and blade tempering progress.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_Scenario7CrucibleHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_Scenario7CrucibleHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the Crucible HUD display values */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario7")
	void UpdateCrucibleHUD(
		float AmbientTempC,
		float HeatExhaustion01,
		float StaminaDrainMult,
		float BladeTempC,
		ETemperedBladeState BladeState,
		ECalderaSurgePhase SurgePhase);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario7")
	float DisplayedAmbientTempC = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario7")
	float DisplayedHeatExhaustion = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario7")
	float DisplayedStaminaDrainMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario7")
	float DisplayedBladeTempC = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario7")
	ETemperedBladeState DisplayedBladeState = ETemperedBladeState::ColdSteel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario7")
	ECalderaSurgePhase DisplayedSurgePhase = ECalderaSurgePhase::DormantCalm;
};

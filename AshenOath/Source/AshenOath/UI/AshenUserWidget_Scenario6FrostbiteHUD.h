// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenUserWidget_Scenario6FrostbiteHUD.generated.h"

/**
 * UAshenUserWidget_Scenario6FrostbiteHUD
 * 
 * UMG HUD displaying somatic frostbite severity, blizzard temperature, companion warmth status, and hearth ignition.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_Scenario6FrostbiteHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_Scenario6FrostbiteHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the Scenario 6 HUD displays */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario6")
	void UpdateScenario6HUD(
		float FrostbiteGauge,
		EFrostbiteSeverity Severity,
		float TemperatureCelsius,
		float HearthIgnition,
		bool bInWarmth);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario6")
	float DisplayedFrostbite = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario6")
	EFrostbiteSeverity DisplayedSeverity = EFrostbiteSeverity::Normal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario6")
	float DisplayedTemperature = -15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario6")
	float DisplayedHearthIgnition = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario6")
	bool bDisplayedInWarmth = false;
};

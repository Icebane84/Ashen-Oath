// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenUserWidget_Scenario8AbyssHUD.generated.h"

/**
 * UAshenUserWidget_Scenario8AbyssHUD
 * 
 * UMG widget displaying Torch Fuel gauge, light radius meter, darkness accuracy penalty, and active sonar ping radius.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_Scenario8AbyssHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_Scenario8AbyssHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the Abyss Catacombs HUD display */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario8")
	void UpdateAbyssHUD(
		float TorchFuel01,
		float LightRadiusUU,
		float AccuracyPenalty01,
		float SonarRadiusUU,
		ELightEnvironmentState LightState);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario8")
	float DisplayedTorchFuel = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario8")
	float DisplayedLightRadiusUU = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario8")
	float DisplayedAccuracyPenalty = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario8")
	float DisplayedSonarRadiusUU = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario8")
	ELightEnvironmentState DisplayedLightState = ELightEnvironmentState::RadiantIlluminated;
};

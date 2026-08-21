// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenUserWidget_OakhavenEncounterHUD.generated.h"

/**
 * UAshenUserWidget_OakhavenEncounterHUD
 * 
 * UMG HUD displaying Brother Malakor's health bar, ritual completion dial, and debt spike warnings.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_OakhavenEncounterHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_OakhavenEncounterHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the encounter status presentation on the HUD */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario1")
	void UpdateHUDState(float BossHealthPercent, float RitualProgressPercent, float CurrentDebt);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario1")
	float DisplayedBossHealth = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario1")
	float DisplayedRitualProgress = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario1")
	float DisplayedIntegrationDebt = 0.0f;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenUserWidget_BossEncounterDynamicHUD.generated.h"

/**
 * UAshenUserWidget_BossEncounterDynamicHUD
 * 
 * UMG/Slate widget displaying the boss health bar, active phase indicator,
 * and companion pinning crisis alerts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BossEncounterDynamicHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_BossEncounterDynamicHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed boss state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Boss")
	void UpdateBossDisplay(const FBossArenaState& State);

	/** Updates the displayed companion crisis state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Boss")
	void UpdateCrisisDisplay(const FCompanionCrisisContext& Context);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Boss")
	EBossEncounterPhase GetDisplayedPhase() const { return DisplayedPhase; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Boss")
	EBossEncounterPhase DisplayedPhase = EBossEncounterPhase::Phase1_Guardian;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Boss")
	float DisplayedHealthPercent = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Boss")
	bool bCrisisAlertVisible = false;
};

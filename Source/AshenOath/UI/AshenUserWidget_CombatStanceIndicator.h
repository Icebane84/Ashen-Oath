// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenResonanceCombatStancesComponent.h"
#include "AshenUserWidget_CombatStanceIndicator.generated.h"

/**
 * UAshenUserWidget_CombatStanceIndicator
 *
 * UMG backing widget rendering the active resonance combat stance HUD indicator and stance transitions.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CombatStanceIndicator : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateStanceDisplay(EAshenCombatStance NewStance, float FrameSpeedMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	EAshenCombatStance ActiveStance = EAshenCombatStance::GuardianStance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveFrameSpeedMultiplier = 1.0f;
};

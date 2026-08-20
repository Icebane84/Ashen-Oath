// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ParryCounterHUD.generated.h"

/**
 * UAshenUserWidget_ParryCounterHUD
 * Micro-second flash ring indicating parry sweet spot and unchained berserk charge meter.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ParryCounterHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bParryWindowActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float UnchainedEnergyRatio = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateCombatHUD(bool bParryActive, float EnergyRatio);
};

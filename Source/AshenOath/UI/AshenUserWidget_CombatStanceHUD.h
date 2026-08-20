// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenUserWidget_CombatStanceHUD.generated.h"

/**
 * UAshenUserWidget_CombatStanceHUD
 * Somatic UI widget displaying radial combat stance wheel, active buffs/debuffs, and transition cooldowns.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CombatStanceHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	ECombatStance DisplayedStance = ECombatStance::Flow;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float StanceCooldownRemaining = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateStanceHUD(ECombatStance InStance, float InCooldown);
};

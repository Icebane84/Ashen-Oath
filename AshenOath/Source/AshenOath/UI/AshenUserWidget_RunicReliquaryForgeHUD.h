// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenUserWidget_RunicReliquaryForgeHUD.generated.h"

/**
 * UAshenUserWidget_RunicReliquaryForgeHUD
 * 
 * UMG/Slate widget displaying the active weapon's socket grid, mass readout,
 * and poise multipliers.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_RunicReliquaryForgeHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_RunicReliquaryForgeHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed forge stats */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Forge")
	void UpdateForgeDisplay(const FSoulForgeWeaponState& State);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Forge")
	float GetDisplayedMassKg() const { return DisplayedMassKg; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Forge")
	float DisplayedMassKg = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Forge")
	float DisplayedPoiseMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Forge")
	int32 DisplayedSocketCount = 0;
};

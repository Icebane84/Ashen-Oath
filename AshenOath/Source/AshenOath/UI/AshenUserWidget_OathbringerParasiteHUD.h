// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenUserWidget_OathbringerParasiteHUD.generated.h"

/**
 * UAshenUserWidget_OathbringerParasiteHUD
 * 
 * UMG widget displaying Oathbringer's dynamic mass (45-220kg), corruption meter, garnet pommel eye emissive glow, and Gloomwood freeze timer.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_OathbringerParasiteHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_OathbringerParasiteHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates HUD display with current blade state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Blade")
	void UpdateBladeHUD(
		float Corruption01,
		float BladeMassKg,
		float SwingPlayRate,
		EBladeParasiteState State,
		bool bFrozen,
		float FreezeTimeRemaining);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Blade")
	float DisplayedCorruption = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Blade")
	float DisplayedMassKg = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Blade")
	float DisplayedPlayRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Blade")
	EBladeParasiteState DisplayedState = EBladeParasiteState::DormantSteel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Blade")
	bool bDisplayedFrozen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Blade")
	float DisplayedFreezeTime = 0.0f;
};

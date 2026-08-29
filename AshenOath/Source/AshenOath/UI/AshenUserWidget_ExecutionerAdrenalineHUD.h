// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenUserWidget_ExecutionerAdrenalineHUD.generated.h"

/**
 * UAshenUserWidget_ExecutionerAdrenalineHUD
 * 
 * Renders the Executioner's Adrenaline Surge gauge, execution prompt icon, and hyper-armor status ring.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ExecutionerAdrenalineHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_ExecutionerAdrenalineHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the adrenaline HUD state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Severance")
	void UpdateAdrenalineHUD(float CurrentAdrenaline, float MaxAdrenaline, bool bHyperArmorActive, bool bExecutionPromptAvailable);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Severance")
	float DisplayedAdrenaline = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Severance")
	bool bDisplayedHyperArmor = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Severance")
	bool bDisplayedExecutionPrompt = false;
};

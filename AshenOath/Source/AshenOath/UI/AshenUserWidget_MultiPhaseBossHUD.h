// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenUserWidget_MultiPhaseBossHUD.generated.h"

/**
 * UAshenUserWidget_MultiPhaseBossHUD
 * Full boss encounter HUD rendering segmented health bars, poise meters, and phase transition title cards.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MultiPhaseBossHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FBossEncounterPayload DisplayBossData;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateBossHUD(const FBossEncounterPayload& InData);
};

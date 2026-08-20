// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenUserWidget_TripartiteResourceHUD.generated.h"

/**
 * UAshenUserWidget_TripartiteResourceHUD
 * Somatic HUD displaying Kaelen's Shadow Mark corruption, Serafina's empathic burnout, and Garrett's sanity posture.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TripartiteResourceHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FTripartiteResourceState DisplayedState;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateResourceState(const FTripartiteResourceState& InState);
};

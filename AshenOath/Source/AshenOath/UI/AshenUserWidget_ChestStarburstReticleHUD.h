// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ChestStarburstReticleHUD.generated.h"

/**
 * UAshenUserWidget_ChestStarburstReticleHUD
 * Diegetic HUD rendering around Kaelen's chest 8-pointed starburst emblem to guide breathing rhythm (Cross: Inhale, Square: Exhale).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ChestStarburstReticleHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsReticleVisible = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SetReticleVisibility(bool bVisible);
};

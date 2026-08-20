// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CampfireSceneHUD.generated.h"

/**
 * UAshenUserWidget_CampfireSceneHUD
 * Campfire party rest screen with dialogue prompts and companion portraits.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CampfireSceneHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsCampfireRestActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SetCampfireHUDActive(bool bActive);
};

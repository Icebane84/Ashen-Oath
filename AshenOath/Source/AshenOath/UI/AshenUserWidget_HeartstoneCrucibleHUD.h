// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_HeartstoneCrucibleHUD.generated.h"

/**
 * UAshenUserWidget_HeartstoneCrucibleHUD
 * Heartstone memory forge interface for transmuting soul remnants into perks.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_HeartstoneCrucibleHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 AvailableSoulRemnants = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateCrucibleRemnants(int32 RemnantCount);
};

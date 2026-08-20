// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenUserWidget_WhiteFlameResolutionHUD.generated.h"

/**
 * UAshenUserWidget_WhiteFlameResolutionHUD
 * Radiant HUD displaying active White Flame duration remaining and live total debt eradicated.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WhiteFlameResolutionHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FWhiteFlameResolutionPayload DisplayPayload;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateWhiteFlameDisplay(const FWhiteFlameResolutionPayload& InPayload);
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VigilTravelMenu.generated.h"

/**
 * UAshenUserWidget_VigilTravelMenu
 *
 * UMG backing widget rendering sanctuary travel route selection and Vigilance meters.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VigilTravelMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateVigilTravelDisplay(float CurrentVigilance, bool bExhausted);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedVigilance = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPartyExhausted = false;
};

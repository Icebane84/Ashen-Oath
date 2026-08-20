// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_TrapChestWarning.generated.h"

/**
 * UAshenUserWidget_TrapChestWarning
 *
 * UMG backing widget rendering "Trap Armed / Disarm Needed" HUD warning banners.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TrapChestWarning : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayTrapWarning(const FText& WarningText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DismissWarning();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedWarningText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bWarningActive = false;
};

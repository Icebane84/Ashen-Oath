// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CrucibleUpgradeMenu.generated.h"

/**
 * UAshenUserWidget_CrucibleUpgradeMenu
 *
 * UMG backing widget rendering Heartstone Crucible upgrade trees and passive boons.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CrucibleUpgradeMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateCrucibleMenuDisplay(int32 CurrentTier, float GlobalMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedTier = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedGlobalMultiplier = 1.0f;
};

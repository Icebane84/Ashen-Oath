// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SanctuaryBlessingMenu.generated.h"

/**
 * UAshenUserWidget_SanctuaryBlessingMenu
 *
 * UMG backing widget rendering Heartstone Crucible blessing selection and active stat boons.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SanctuaryBlessingMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateBlessingMenuDisplay(FName BlessingID, float BuffMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedBlessingID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedBuffMultiplier = 1.0f;
};

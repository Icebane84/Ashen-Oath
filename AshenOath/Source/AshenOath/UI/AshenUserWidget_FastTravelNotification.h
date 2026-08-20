// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_FastTravelNotification.generated.h"

/**
 * UAshenUserWidget_FastTravelNotification
 *
 * UMG backing widget rendering "Sanctuary Discovered / Fast Travel Unlocked" banner animations.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_FastTravelNotification : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplaySanctuaryUnlockedNotification(FName SanctuaryID, const FText& SanctuaryName);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DismissNotification();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedSanctuaryID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedSanctuaryName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bNotificationActive = false;
};

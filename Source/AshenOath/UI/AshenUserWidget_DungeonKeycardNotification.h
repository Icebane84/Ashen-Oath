// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_DungeonKeycardNotification.generated.h"

/**
 * UAshenUserWidget_DungeonKeycardNotification
 *
 * UMG backing widget rendering "Rune Key Acquired" HUD notification banners.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DungeonKeycardNotification : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayKeycardAcquiredNotification(FName KeycardID, const FText& KeycardNameText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DismissNotification();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName AcquiredKeycardID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText AcquiredKeycardName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bNotificationActive = false;
};

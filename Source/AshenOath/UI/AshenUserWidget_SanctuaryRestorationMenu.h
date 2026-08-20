// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SanctuaryRestorationMenu.generated.h"

/**
 * UAshenUserWidget_SanctuaryRestorationMenu
 *
 * UMG backing widget rendering Dormant Heartstone rekindling status and Sanctuary upgrades.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SanctuaryRestorationMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateSanctuaryRestorationDisplay(FName SanctuaryID, int32 ActiveSanctuaries);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedSanctuaryID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 TotalActiveSanctuariesCount = 0;
};

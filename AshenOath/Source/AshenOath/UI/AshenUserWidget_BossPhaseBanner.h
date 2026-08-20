// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BossPhaseBanner.generated.h"

/**
 * UAshenUserWidget_BossPhaseBanner
 *
 * UMG backing widget rendering animated boss phase transition banners.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BossPhaseBanner : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayPhaseBanner(int32 PhaseIndex, const FText& PhaseTitleText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DismissPhaseBanner();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 ActivePhaseIndex = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText ActivePhaseTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bBannerActive = false;
};

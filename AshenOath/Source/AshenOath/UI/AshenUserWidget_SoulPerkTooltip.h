// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SoulPerkTooltip.generated.h"

/**
 * UAshenUserWidget_SoulPerkTooltip
 *
 * UMG backing widget rendering hover tooltips for Soul Constellation perk nodes.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SoulPerkTooltip : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayPerkTooltip(FName PerkID, const FText& Title, const FText& Description, float AshCost, bool bIsUnlocked, bool bPrereqMet);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HideTooltip();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedPerkID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedDescription;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedAshCost = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPerkUnlocked = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPrerequisitesMet = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bTooltipVisible = false;
};

// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_HUD.generated.h"

class UProgressBar;
class UTextBlock;

/**
 * UAshenUserWidget_HUD
 * C++ Base Class for the Player HUD UMG Widget.
 * Implements BindWidget elements for Health, XP, and Level text, and auto-listens to delegates.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_HUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* XPBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LevelText;

private:
	UFUNCTION()
	void HandleHealthChanged(float CurrentHealth, float MaxHealth);

	UFUNCTION()
	void HandleXpGained(int32 AmountGained, int32 TotalXp);

	UFUNCTION()
	void HandleLevelUp(int32 NewLevel);

	void InitializeHUD();
};

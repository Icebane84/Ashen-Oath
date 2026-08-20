// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PauseSettingsMenu.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPauseMenuActionExecutedSignature, FString, ActionName);

/**
 * UAshenUserWidget_PauseSettingsMenu
 *
 * UMG backing widget managing in-game pause menu actions and system settings:
 *  - Resume Game
 *  - Set Master Volume
 *  - Save & Exit to Main Menu
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PauseSettingsMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ResumeGame();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void SetMasterVolume(float Volume);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void SaveAndExitToMainMenu();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float MasterVolume = 1.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnPauseMenuActionExecutedSignature OnActionExecuted;
};

// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenUserWidget_InnerMonologueSubtitleHUD.generated.h"

/**
 * UAshenUserWidget_InnerMonologueSubtitleHUD
 * 
 * Subtle HUD rendering internal monologue text:
 * - ShadowSelf: Violet/grey distorted italics
 * - Eldrin: Pale cyan sorrowful serif
 * - KaelenReflex: Warm amber standard typography
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_InnerMonologueSubtitleHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_InnerMonologueSubtitleHUD(const FObjectInitializer& ObjectInitializer);

	/** Displays internal monologue */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Voice")
	void DisplayMonologue(const FString& Text, EVoiceChannel Channel, float DurationSeconds = 4.0f);

	/** Clears subtitle display */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Voice")
	void ClearMonologue();

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Voice")
	bool IsDisplaying() const { return bActive; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Voice")
	FString CurrentMonologueText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Voice")
	EVoiceChannel CurrentChannel = EVoiceChannel::ShadowSelf;

private:
	bool bActive = false;
};

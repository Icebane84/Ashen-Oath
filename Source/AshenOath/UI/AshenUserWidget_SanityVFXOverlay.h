// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SanityVFXOverlay.generated.h"

/**
 * UAshenUserWidget_SanityVFXOverlay
 *
 * UMG backing widget rendering HUD Sanity vignette pulse & auditory whisper subtitles.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SanityVFXOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplaySanityVFXOverlay(float SanityPercentage, const FText& AuditoryWhisperSubtitle);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HideOverlay();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedSanityPercentage = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedWhisperSubtitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bOverlayActive = false;
};

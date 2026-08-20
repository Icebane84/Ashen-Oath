// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenUserWidget_AudioAccessibilitySubtitleHUD.generated.h"

/**
 * UAshenUserWidget_AudioAccessibilitySubtitleHUD
 * Accessible visual redundancy HUD displaying origin-tagged subtitles ([Controller], [World], [Internal]) to ensure no gameplay cues are missed.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_AudioAccessibilitySubtitleHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FString DisplayedSubtitle = TEXT("");

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EAudioConsciousnessChannel DisplayedChannel = EAudioConsciousnessChannel::WorldSpatial;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayOriginTaggedSubtitle(const FString& Line, EAudioConsciousnessChannel Channel);
};

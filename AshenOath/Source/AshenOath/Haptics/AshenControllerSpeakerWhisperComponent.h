// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenControllerSpeakerWhisperComponent.generated.h"

/**
 * UAshenControllerSpeakerWhisperComponent
 * 
 * Manages audio buffer packaging and haptic clicks for companion whispers
 * routed directly through the controller speaker.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenControllerSpeakerWhisperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenControllerSpeakerWhisperComponent();

	/** Packages and prepares a companion whisper packet */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Haptics")
	FTactileWhisperPayload PrepareWhisper(
		ETactileWhisperChannel Channel,
		const FString& DialogueLine,
		float Volume);

	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	bool IsSpeakerEnabled() const { return bSpeakerEnabled; }

	UFUNCTION(BlueprintCallable, Category = "Ashen|Haptics")
	void SetSpeakerEnabled(bool bEnabled) { bSpeakerEnabled = bEnabled; }

private:
	bool bSpeakerEnabled = true;
};

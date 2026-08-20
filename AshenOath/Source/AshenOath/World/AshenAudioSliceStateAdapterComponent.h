// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenAudioSliceStateAdapterComponent.generated.h"

/**
 * UAshenAudioSliceStateAdapterComponent
 *
 * Modular Audio Slice adapter.
 * Consumes FSoulStateVector invalidation pulses to drive whisper volume and spatialization density.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioSliceStateAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAudioSliceStateAdapterComponent();

	/** Callback when canonical FSoulStateVector invalidates */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioSlice")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	/** Returns whisper volume multiplier */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioSlice")
	float GetWhisperVolumeMultiplier() const { return WhisperVolumeMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|AudioSlice")
	float WhisperVolumeMultiplier = 0.0f;
};

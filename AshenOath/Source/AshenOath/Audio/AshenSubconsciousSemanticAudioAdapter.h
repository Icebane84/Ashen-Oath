// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenSubconsciousSemanticAudioAdapter.generated.h"

class USoundBase;
class UAudioComponent;

/**
 * UAshenSubconsciousSemanticAudioAdapter
 * 
 * Routes validated internal monologue audio motifs:
 * - EVoiceChannel::ShadowSelf -> Direct to DualSense controller speaker
 * - EVoiceChannel::Eldrin / WhiteFlame -> 3D world spatial audio with low-pass reverb
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSubconsciousSemanticAudioAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSubconsciousSemanticAudioAdapter();

	/** Dispatches audio cue based on voice channel */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Voice")
	void DispatchMonologueAudio(EVoiceChannel Channel, USoundBase* CueSound);

	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Voice")
	bool IsControllerSpeakerRouting(EVoiceChannel Channel) const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* SpatialAudioComponent;
};
